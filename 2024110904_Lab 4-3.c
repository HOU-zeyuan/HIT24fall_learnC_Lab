#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

int getPeachNumber(int n)
{
    static int day = 9;
    if (day >= 1)
    {
        printf("第%d天所剩桃子%d个\n", day, 2 * (n + 1));
        day--;
        return getPeachNumber(2 * (n + 1));
    }
    else
        return n ;
}

int main()
{
    int num = getPeachNumber(1);
    printf("猴子第一天摘了：%d个桃子。\n", num);
    return 0;
}