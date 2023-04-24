# Level09

Now enumerate:

    level09@SnowCrash:~$ ls -al
    total 24
    dr-x------ 1 level09 level09  140 Mar 5 2016 .
    d--x--x--x 1 root  users  340 Aug 30 2015 ..
    -rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
    ----r--r-- 1 flag09  level09 26 Mar  5  2016 token
    level09@SnowCrash:~$ cat token
    f4kmm6p|=?p?n??DB?Du{??
    level09@SnowCrash:~$ ./level09
    You need to provied only one arg.
    level09@SnowCrash:~$ ./level09 token
    tpmhr
now let's test the output of level09:

    level09@SnowCrash:~$ ./level09 a
    a
    level09@SnowCrash:~$ ./level09 ab
    ac
    level09@SnowCrash:~$ ./level09 abc
    ace
    level09@SnowCrash:~$ ./level09 salut
    sbnxx
    level09@SnowCrash:~$ ./level09 "01234"
    02468
We can see that it encrypts the string by adding the index to the value of each char of the string, let's do a code to reverse this:

    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    int main(int ac, char **av) {
        int i = 0;
        int fd = 0;

        if (ac == 2) {
                fd = open(av[1], O_RDONLY);
                if (fd != -1) {
                        char buf[1024];

                        int ret = 0;
                        while ((ret = read(fd, buf, 1))) {
					if (i != 25) {
                                  printf("%c", buf[0] - i);
                                  ++i;
					}
                        }
                        printf("\n");
                }
        }
        return 0;
    }
  We run our code with the token file as argument :
  

    ➜  ~ gcc crash.c
    ➜  ~ ./a.out token
    f3iji1ju5yuevaus41q1afiuq

