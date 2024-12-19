#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *data;
    struct Node *next;
}Node, *LinkedList;

void add(LinkedList head, char *Data){
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=strdup(Data);
    
    LinkedList pre=head;
    while(pre->next) pre=pre->next;
    pre->next=new, new->next=NULL;
}

void select(LinkedList head){
    LinkedList now=head->next;
    int max=0;
    char *maxData=NULL;
    while(now){
        int len=strlen(now->data);
        if(len>max){
            maxData=strdup(now->data);
            max=len;
        }
        now=now->next;
    }
    printf("%s\n", maxData);
}

void delete(LinkedList head){
    Node *now=head->next;
    while(now){
        Node *temp=now;
        now=now->next;
        free(temp->data), free(temp);
    }
}

int main(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;

    while(1){
        char *input=(char*)malloc(sizeof(char)*101);
        gets(input);

        if(strcmp(input, "******")==0) break;
        else add(head, input);
        free(input);
    }
    select(head);

    delete(head);
    return 0;
}