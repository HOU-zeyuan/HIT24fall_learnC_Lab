#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int n){
    for(int i=3; i<sqrt(n); i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    int*arr=(int*)malloc(sizeof(int)*(b-a+1));
    for(int i=a;i<=b;i++){
        if(i%2==0) continue;
        int reverse_num=0, copy_num=i;
        while(copy_num>0){
            reverse_num=reverse_num*10+copy_num%10;
            copy_num/=10;
        }
        if(reverse_num==i) if(is_prime(i)) printf("%d\n", i);
    }
    free(arr);
    return 0;
}
