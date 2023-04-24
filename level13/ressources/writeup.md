# Level 13

# Enumerate

    level13@SnowCrash:~$ ls -la
	total 20
	dr-x------ 1 level13 level13  120 Mar  5  2016 .
	d--x--x--x 1 root    users    340 Aug 30  2015 ..
	-r-x------ 1 level13 level13  220 Apr  3  2012 .bash_logout
	-r-x------ 1 level13 level13 3518 Aug 30  2015 .bashrc
	-rwsr-sr-x 1 flag13  level13 7303 Aug 30  2015 level13
	-r-x------ 1 level13 level13  675 Apr  3  2012 .profile
	level13@SnowCrash:~$ ls
	level13
	level13@SnowCrash:~$ ./level13
	UID 2013 started us but we we expect 4242
To execute this binary we need to be a user with 4242 as UID, we have two ways to do this:

# Copy the binary and create a User (UID=4242)

    scp -P 4242 level13 kali@localhost:~/Desktop
    sudo useradd -u 4242 newuser ( ou juste useradd newuser et usermod -u 4242 newuser)
    sudo passwd newuser (to set a password)
    su newuser
    ./level13
    your token is 2A31L79asukciNyi8uppkEuSx

# Changing memory during execution

Let's try using gdb:

    level13@SnowCrash:~$ gdb level13
    Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
    (gdb) disas main
    Dump of assembler code for function main:
	   0x0804858c <+0>:	push   %ebp
	   0x0804858d <+1>:	mov    %esp,%ebp
	   0x0804858f <+3>:	and    $0xfffffff0,%esp
	   0x08048592 <+6>:	sub    $0x10,%esp
	   0x08048595 <+9>:	call   0x8048380 <getuid@plt>
	   0x0804859a <+14>:	cmp    $0x1092,%eax
	   0x0804859f <+19>:	je     0x80485cb <main+63>
	   0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
	   0x080485a6 <+26>:	mov    $0x80486c8,%edx
	   0x080485ab <+31>:	movl   $0x1092,0x8(%esp)
	   0x080485b3 <+39>:	mov    %eax,0x4(%esp)
	   0x080485b7 <+43>:	mov    %edx,(%esp)
	   0x080485ba <+46>:	call   0x8048360 <printf@plt>
	   0x080485bf <+51>:	movl   $0x1,(%esp)
	   0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
	   0x080485cb <+63>:	movl   $0x80486ef,(%esp)
	   0x080485d2 <+70>:	call   0x8048474 <ft_des>
	   0x080485d7 <+75>:	mov    $0x8048709,%edx
	   0x080485dc <+80>:	mov    %eax,0x4(%esp)
	   0x080485e0 <+84>:	mov    %edx,(%esp)
	   0x080485e3 <+87>:	call   0x8048360 <printf@plt>
	   0x080485e8 <+92>:	leave
	   0x080485e9 <+93>:	ret
	End of assembler dump.
We see that there is a comparison between $0x1092(=4242) and eax registry let's modift eax during exec:

    (gdb) b getuid
	Breakpoint 1 at 0x8048380
	(gdb) r
	Starting program: /home/user/level13/level13

	Breakpoint 1, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
	(gdb) p $eax
	$1 = 1
	(gdb) step
	Single stepping until exit from function getuid,
	which has no line number information.
	0x0804859a in main ()
	(gdb) p $eax
	$2 = 2013
	(gdb) p $eax=4242
	$3 = 4242
	(gdb) step
	Single stepping until exit from function main,
	which has no line number information.
	your token is 2A31L79asukciNyi8uppkEuSx
