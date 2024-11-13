#include <stdio.h>
int main()
{
    int mode;
    float temp, ans;
    printf("Fahrenheit--->Centigrade: 0    Centigrade--->Fahrenheit: 1\n");
    printf("Input the temperature:\n(two inputs in one line, separated by space)\n");
    scanf("%d %f", &mode, &temp);
    if (mode == 0)
    {
        ans = (temp - 32) * 5 / 9;
        printf("The Centigrade is %.2f", ans);
    }
    else if (mode == 1)
    {
        ans = (temp * 9 / 5) + 32;
        printf("The Fahrenheit is %.2f", ans);
    }
    return 0;
}