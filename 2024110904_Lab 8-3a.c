#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

void add(LinkedList h, int data){
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=data;
    LinkedList pre=h;
    while(pre->next!=NULL) pre=pre->next;
    pre->next=new, new->next=NULL;
}

void convert(int *arr, char *str, int *len){
    int i=0, index=0, temp=0;
    while(str[i]!='\0'){
        if(str[i]==' ') arr[index++]=temp, temp=0;
        else temp=temp*10+str[i]-'0';
        i++;
    }
    arr[index++]=temp;
    *len=index;
}

void init(LinkedList h1, LinkedList h2){
    printf("Enter the number of elements in the first list in an increasing order: (in one line, each number separated by a space)\n");
    char *str1=(char*)malloc(sizeof(char)*10000), *str2=(char*)malloc(sizeof(char)*10000);
    gets(str1);
    printf("Enter the number of elements in the second list in an increasing order: (in one line, each number separated by a space)\n");
    gets(str2);
    int arr1[10000], arr2[10000], index1=0, index2=0;
    convert(arr1, str1, &index1);
    convert(arr2, str2, &index2);

    for(int i=0; i<index1; i++) add(h1, arr1[i]);
    for(int i=0; i<index2; i++) add(h2, arr2[i]);
}

void solve(LinkedList h1, LinkedList h2){
    LinkedList p1=h1->next, p2=h2->next;
    while(p1!=NULL && p2!=NULL){
        while(p1->data<p2->data && p1->next!=NULL) p1=p1->next;
        if(p1->next==NULL && p1->data<p2->data) break;
        LinkedList pre=h1;
        while(pre->next!=p1) pre=pre->next;
        Node *new=(Node*)malloc(sizeof(Node));
        new->data=p2->data;
        new->next=p1, pre->next=new;
        p2=p2->next;
    }
    while(p2!=NULL){
        add(h1, p2->data);
        p2=p2->next;
    }
}

void print(LinkedList h){
    LinkedList p=h->next;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void destroy(LinkedList h){
    LinkedList p=h->next;
    while(p!=NULL){
        LinkedList temp=p;
        p=p->next;
        free(temp);
    }
}

int main(){
    Node *head1=(Node*)malloc(sizeof(Node)), *head2=(Node*)malloc(sizeof(Node));
    head1->next=NULL, head2->next=NULL;

    init(head1, head2);
    solve(head1, head2);
    print(head1);
    destroy(head1), destroy(head2);
    return 0;
}