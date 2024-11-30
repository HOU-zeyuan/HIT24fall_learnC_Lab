#include <stdio.h>

int a, b;

int main() {
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int *p=&a, *q=&b;
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;

    printf("After swapping: %d, %d", a, b);
    return 0;
}