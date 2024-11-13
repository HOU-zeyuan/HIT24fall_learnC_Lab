#include <stdio.h>
int main(void)
{
    short x = 04, y = 40;
    printf("%5hd%5hd%5hd\n", !x, x || y, x && y);
    printf("%5hu%5hd%5hd\n", ~x, x | y, x & y);
    printf("%5hd%5hd%5hd\n \n", ~x, x | y, x & y);
}