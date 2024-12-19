#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_linked_list.h"

void print(LinkedList head){
    printf("目前链表为：");
    if(head->next==NULL){
        printf("空\n");
        return;
    }
    LinkedList now=head->next;
    while(now!=NULL){
        if(now->next) printf("%s->", now->data);
        else printf("%s", now->data);
        now=now->next;
    }
    printf("\n");
}

void add(LinkedList head){
    int index;
    char *data;
    printf("请输入您要添加的数据：\n");
    scanf("%d %s", &index, data);

    LinkedList pre=head;
    for(int i=0; (i<=index-1 && pre->next!=NULL); i++) pre=pre->next;
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=strdup(data);
    new->next=pre->next, pre->next=new;

    printf("数据已添加\n");
    print(head);
}

void delete(LinkedList head){
    char *data;
    printf("请输入您要删除的数据：\n");
    scanf("%s", data);

    LinkedList now=head->next;
    while(now){
        if(strcmp(now->data, data)==0){
            LinkedList pre=head;
            while(pre->next!=now) pre=pre->next;
            pre->next=now->next;
            free(now->data), free(now);
            
            printf("数据已删除\n");
            print(head);
            return;
        }
        now=now->next;
    }
    printf("该数据不存在于链表中\n");
    print(head);
}

void search(LinkedList head){
    char *data;
    printf("请输入您要查找的数据：\n");
    scanf("%s", data);

    LinkedList now=head->next;
    int index=0;
    while(now){
        if(strcmp(now->data, data)==0){
            printf("数据在链表中的位置为：%d\n", index);
            print(head);
            return;
        }
        now=now->next, index++;
    }
    printf("该数据不存在于链表中\n");
    print(head);
}

void update(LinkedList head){
    int index;
    char *data;
    printf("请输入您要更新的数据：\n");
    scanf("%d %s", &index, data);

    LinkedList pre=head;
    for(int i=0; (i<=index-1 && pre->next!=NULL); i++) pre=pre->next;
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=strdup(data);
    if(pre->next==NULL) new->next=NULL, pre->next=new;
    else new->next=pre->next->next, pre->next=new;

    printf("数据已更新\n");
    print(head);
}

void exchange(LinkedList head){
    LinkedList now=head->next;
    while(now->next){
        if(strcmp(now->data, now->next->data)){
            char *temp=now->data;
            now->data=strdup(now->next->data);
            now->next->data=strdup(temp);
            free(temp);
        }
        now=now->next->next;
    }
    print(head);
}

void empty(LinkedList head){
    LinkedList now=head->next;
    while(now){
        LinkedList temp=now;
        now=now->next;
        free(temp->data), free(temp);
    }
}