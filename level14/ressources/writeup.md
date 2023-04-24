# Level 14

# Enumerate

    level14@SnowCrash:~$ ls
	level14@SnowCrash:~$ find / -user flag14 2>/dev/null
Hmm nothing, looks like we are gonna have to try and directly use getflag

# Injection
When disassembling the main function we see a call to ptrace and later a call to getuid


    cat /etc/passwd
    flag00:x:3000:3000::/home/flag/flag00:/bin/bash
	flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
	flag02:x:3002:3002::/home/flag/flag02:/bin/bash
	flag03:x:3003:3003::/home/flag/flag03:/bin/bash
	flag04:x:3004:3004::/home/flag/flag04:/bin/bash
	flag05:x:3005:3005::/home/flag/flag05:/bin/bash
	flag06:x:3006:3006::/home/flag/flag06:/bin/bash
	flag07:x:3007:3007::/home/flag/flag07:/bin/bash
	flag08:x:3008:3008::/home/flag/flag08:/bin/bash
	flag09:x:3009:3009::/home/flag/flag09:/bin/bash
	flag10:x:3010:3010::/home/flag/flag10:/bin/bash
	flag11:x:3011:3011::/home/flag/flag11:/bin/bash
	flag12:x:3012:3012::/home/flag/flag12:/bin/bash
	flag13:x:3013:3013::/home/flag/flag13:/bin/bash
	flag14:x:3014:3014::/home/flag/flag14:/bin/bash
A quick look at /etc/passwd let's us see that the uid of flag14 is 3014
Now let's gdb getflag:

    (gdb) b ptrace
	Breakpoint 1 at 0x8048540
	(gdb) b getuid
	Breakpoint 2 at 0x80484b0
	(gdb) r
	Starting program: /bin/getflag

	Breakpoint 1, 0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6
First the check of ptrace:

	(gdb) p $eax
	$1 = 0
	(gdb) step
	Single stepping until exit from function ptrace,
	which has no line number information.
	0x0804898e in main ()
	(gdb) p $eax
	$2 = -1
	(gdb) p $eax=0
	$3 = 0
	(gdb) step
	Single stepping until exit from function main,
	which has no line number information.
Then the check of getuid:

	Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
	(gdb) p $eax
	$4 = 32
	(gdb) step
	Single stepping until exit from function getuid,
	which has no line number information.
	0x08048b02 in main ()
	(gdb) p $eax
	$5 = 2014
	(gdb) p $eax=3014
	$6 = 3014
	(gdb) step
	Single stepping until exit from function main,
	which has no line number information.
	Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
