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
