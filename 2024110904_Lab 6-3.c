#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input, *output;

void compress(char *input, char *output){
    int count=1;
    struct Index{
        int sum;
        int index;
    }inx;
    inx.sum=0, inx.index=1;
    for(int i=1; i<strlen(input); i++){
        if(i==1 && input[i]!=input[i-1]){
            output[inx.sum]='1';
            output[inx.index]=input[i-1];
            inx.sum+=2, inx.index+=2;
        }
        else if(input[i]!=input[i-1]){
            output[inx.sum]=count+'0';
            output[inx.index]=input[i-1];
            count=1, inx.sum+=2, inx.index+=2;
        }
        else count++;
    }
    output[inx.sum]=count+'0';
    output[inx.index]=input[strlen(input)-1];
    output[inx.index+1]='\0';
}

int main(){
    input=(char*)malloc(sizeof(char)*10000);
    output=(char*)malloc(sizeof(char)*10000);
    scanf("%s",input);

    if(strlen(input)<=2) printf("There's no need to compress it.");
    else compress(input, output);
    printf("%s",output);

    free(input), free(output);
    return 0;
}