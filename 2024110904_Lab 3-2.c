#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int arr[4] = {160, 40, 50, 80};

int main()
{
    for (int a = 1; a * arr[0] <= 900; a++)
    {
        for (int b = 0; a * arr[0] + b * arr[1] <= 900; b++)
        {
            for (int c = 0; a * arr[0] + b * arr[1] + c * arr[2] <= 900; c++)
            {
                if ((900 - a * arr[0] - b * arr[1] - c * arr[2]) % arr[3] == 0 && (b > 0 || c > 0) && (a + b + c + (900 - a * arr[0] - b * arr[1] - c * arr[2]) / arr[3]) <= 10)
                {
                    printf("%d %d %d %d\n", a, b, c, (900 - a * arr[0] - b * arr[1] - c * arr[2]) / arr[3]);
                }
            }
        }
    }
    return 0;
}