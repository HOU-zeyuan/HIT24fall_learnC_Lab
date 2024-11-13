#include <stdio.h>
int main()
{   int t;
    scanf("%d", &t);

    if(t >=0 && t < 12) printf("good morning.");
    else if(t == 12) printf("good noon.");
    else if(t >= 13 && t < 18) printf("good afternoon.");
    else if(t >= 18 && t < 21) printf("good evening.");
    else if(t >= 21 && t < 24) printf("good night.");
    else printf("the input is invalid.");

    return 0;
}
