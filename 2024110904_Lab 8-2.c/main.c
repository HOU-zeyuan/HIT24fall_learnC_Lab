#include <stdio.h>
#include <stdlib.h>
#include "my_linked_list.h"

int mode=-1;
char *menu[7]={
    "1.增加数据",
    "2.删除数据",
    "3.查找数据",
    "4.更新数据",
    "5.交换节点",
    "0.退出",
    "请输入你的选择："
};

int main(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;

    while(mode!=0){
        for(int i=0;i<7;i++) printf("%s\n",menu[i]);
        scanf("%d",&mode);

        switch(mode){
            case 1:
                add(head);
                break;
            case 2:
                delete(head);
                break;
            case 3:
                search(head);
                break;
            case 4:
                update(head);
                break;
            case 5:
                exchange(head);
                break;
            case 0:
                empty(head);
                break;
            default:
                break;
        }
    }
}