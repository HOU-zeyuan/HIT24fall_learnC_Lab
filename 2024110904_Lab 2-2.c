#include <stdio.h>
int main()
{   char n;
    scanf("%c", &n);
    if (n < 'A' || n > 'z' || (n > 'Z' && n < 'a')) printf("Invalid character!");
    else
    {   if (n > 'Z') n = n - 'a' + 'A';

        int length = (int)(n - 'A')+1;
        for (int i = (int)'A'; i <= (int)n; i++)
        {   for (int j = length; j > 0; j--) printf(" ");
            for (int k = (int)'A'; k <= i; k++) printf("%c", k);
            for (int l = i - 1; l >= (int)'A'; l--) printf("%c", l);
            printf("\n");
            length--;
        }
    }

    return 0;
}
