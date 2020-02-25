#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>

int             main(void)
{
    int         fd1;
    int         fd2;
    char        *line1 = NULL;
    char        *line2 = NULL;
    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);

while (get_next_line(fd1, &line1) && get_next_line(fd2, &line2))
    {
        printf("\n%s", line1);
        printf("\n\t%s", line2);
    }
    return (0);
}