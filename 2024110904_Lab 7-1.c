#include <stdio.h>

int main(){
    struct test1{
        char a;
        float c;
        double d;
        int e;
        char f;
    };

    struct test2{
        char c;
        int *p1;
        int t;
        double *p2;
    };

    struct S1{
        char c1;
        int i;
    };

    struct S2{
        char c2;
        struct S1 s;
        char c3;
    };

    printf("Size of test1: %d\n", sizeof(struct test1));//输出为24，因为(1+3)+4+8+4+(1+3)=24
    printf("Size of test2: %d\n", sizeof(struct test2));//输出为32，因为(1+7)+8+(4+4)+8=32
    printf("Size of S1: %d\n", sizeof(struct S1));//输出为8，因为(1+3)+4=8
    printf("Size of S2: %d\n", sizeof(struct S2));//输出为16，因为(1+3)+[(1+3)+4]+(1+3)=16
    return 0;
}