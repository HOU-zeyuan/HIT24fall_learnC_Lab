#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

int Gcd(int a, int b)
{
    if (b != 0)
    {
        int c = a % b;
        a = b, b = c;
        return Gcd(a, b);
    }
    else
        return a;
}

int main()
{
    int a, b;
    printf("Input a,b\n");
    scanf("%d,%d", &a, &b);
    int temp_a = a, temp_b = b;
    if (a <= 0 || b <= 0)
        printf("Input number should be positive!\n");
    else
    {
        if (a < b)
        {
            int temp = a;
            a = b, b = temp;
        }

        printf("Greatest Common Divisor of %d and %d is %d\n", temp_a, temp_b, Gcd(a, b));
    }
    return 0;
}