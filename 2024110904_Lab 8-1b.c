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

void write(LinkedList head, char *filename){
    FILE *file=fopen(filename, "w");
    Node *now=head->next;
    while(now){
        if(!now->next) fprintf(file, "%s", now->data);
        else fprintf(file, "%s\n", now->data);
        now=now->next;
    }
    fclose(file);
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
        char *input=(char*)malloc(sizeof(char)*51);
        gets(input);

        if(strcmp(input, "******")==0) break;
        else add(head, input);
        free(input);
    }
    write(head, "Input.txt");

    delete(head);
    return 0;
}