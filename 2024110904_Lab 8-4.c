#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *data;
    struct Node *next;
}Node, *LinkedList;

typedef struct Node2{
    char *data;
    struct Node2 *next;
}Node2, *Stack;

void add(LinkedList h, char *str){
    LinkedList pre=h;
    while(pre->next!=NULL) pre=pre->next;
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=strdup(str);
    new->next=NULL, pre->next=new;
}

void convert(char *str1, char **str2, int *len){
    int index1=0, index2=0, i=0;
    str2[index1]=(char*)malloc(sizeof(char)*100);
    while(str1[i]!='\0'){
        if(str1[i]==' '){
            str2[index1++][index2]='\0';
            index2=0;
            str2[index1]=(char*)malloc(sizeof(char)*100);
        }
        else str2[index1][index2++]=str1[i];
        i++;
    }
    str2[index1++][index2]='\0';
    *len=index1;
}

void push(Stack s, char *str){
    Node2 *new=(Node2*)malloc(sizeof(Node2));
    new->data=strdup(str);
    new->next=s->next, s->next=new;
}

void pop(Stack s, LinkedList h, int index){
    Node2 *temp=s->next;
    s->next=temp->next;
    LinkedList pre=h;
    while(index--) pre=pre->next;
    free(pre->next->data);
    pre->next->data=strdup(temp->data);
    free(temp->data), free(temp);
}

void init(LinkedList h){
    printf("Enter each element of the list: (in one line, separated by spaces)\n");
    char *str1=(char*)malloc(sizeof(char)*1000);
    gets(str1);
    char **str2=(char**)malloc(sizeof(char*)*1000);
    int len=0;
    convert(str1, str2, &len);
    for(int i=0; i<len; i++){
        add(h, str2[i]);
        free(str2[i]);
    }
    free(str1), free(str2);
}

void solve(LinkedList h, Stack s){
    LinkedList p=h->next;
    while(p!=NULL){
        push(s, p->data);
        p=p->next;
    }
    int index=0;
    while(s->next!=NULL) pop(s, h, index++);
}

void print(LinkedList h){
    LinkedList p=h->next;
    while(p!=NULL){
        printf("%s\n", p->data);
        p=p->next;
    }
}

void destroy(LinkedList h){
    LinkedList p=h->next;
    while(p!=NULL){
        LinkedList temp=p;
        p=p->next;
        free(temp->data), free(temp);
    }
}

void destroyStack(Stack s){
    Stack p=s->next;
    while(p!=NULL){
        Stack temp=p;
        p=p->next;
        free(temp->data), free(temp);
    }
}

int main(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    Node2 *top=(Node2*)malloc(sizeof(Node2));
    top->next=NULL;

    init(head);
    solve(head, top);
    print(head);
    destroy(head), destroyStack(top);
    return 0;
}