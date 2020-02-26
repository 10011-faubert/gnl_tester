#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int             main(void)
{
    int             fd1;
    int             fd2;
    char            *line1;
    char            *line2;
    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    int             ret1 = 1;
    int             ret2 = 1;

    srand(time(NULL));
    while (ret1 || ret2)
    {
        if (ret1 && rand() % 8)
        {
            ret1 = get_next_line(fd1, &line1);
            printf("\n%d : %s", ret1, line1);
        }
        if (ret2 && rand() % 2)
        {
            ret2 = get_next_line(fd2, &line2);
            printf("\n%d : %s", ret2, line2);
        }
    }
    return (0);
}