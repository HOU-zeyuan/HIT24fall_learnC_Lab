#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int n)
{
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= (int)sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int *list1 = (int *)malloc((b - a + 1) * sizeof(int));
    int index = 0;

    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            continue;
        int digit[10];
        int temp = 0, copy = i;
        while (copy > 0)
        {
            digit[temp] = copy % 10;
            copy = copy / 10;
            temp++;
        }

        int judge = 0;
        for (int j = 0; j < (temp / 2); j++)
        {
            if (digit[j] != digit[temp - j - 1])
            {
                judge = 1;
                break;
            }
        }
        if (judge == 0)
        {
            list1[index] = i;
            index++;
        }
    }

    for (int k = 0; k < index; k++)
    {
        if (is_prime(list1[k]) == 1)
            printf("%d\n", list1[k]);
    }
    free(list1);
    return 0;
}