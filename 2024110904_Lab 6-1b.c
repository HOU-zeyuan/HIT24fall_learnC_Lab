#include <stdio.h>

int a, b;

void swap_num(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    swap_num(&a, &b);

    printf("After swapping: %d %d", a, b);
    return 0;
}