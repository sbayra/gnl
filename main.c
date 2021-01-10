#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int                             get_next_line(int fd, char **line);

int main()
{
        int             fd;
        int             i;
        int             j;
        char                    *line = 0;
        char                    *lineadress[66];

        j = 1;
    printf("\n==========================================\n");
    printf("========= TEST 8 : Wrong Input ===========\n");
    printf("==========================================\n\n");

    if ((i = get_next_line(180, &line)) == -1)
        printf("Well Done, you return -1 if no FD\n\n");
    else {
        printf("Not Good, you don't return -1 if no FD\n\n");
        printf("i = %i", i);
    }
    return (0);
}
