#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;

    if(n<1) printf("Invalid input.\n");
    else{
    int v = 25, t = 2;
    for (int i = 0; i < n; i++)
    {
        sum += v * t;
        v *= 2, t += 2;
    }

    printf("%d\n", sum);
    }
    return 0;
}