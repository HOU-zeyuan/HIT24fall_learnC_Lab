#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct Event{
    int begin_hour;
    int end_hour;
}Event;

Event *event;

void init(){
    printf("How many events?\n");
    scanf("%d", &n);
    printf("begin_hour end_hour:\n");
    event=(Event*)malloc(sizeof(Event)*n);
    for(int i=0; i<n; i++) scanf("%d %d", &event[i].begin_hour, &event[i].end_hour);
}

void swap(Event *a, Event *b){
    Event t=*a;
    *a=*b, *b=t;
}

void three_qsort1(int left, int right){
    if(left>=right) return;
    int l=left, r=right, mid=l+(r-l)/2;
    int i=l;
    while(i<=r){
        if(event[i].begin_hour<event[mid].begin_hour)  swap(&event[i++], &event[l++]);
        else if(event[i].begin_hour>event[mid].begin_hour)  swap(&event[i], &event[r--]);
        else i++;
    }
    three_qsort1(left, l-1);
    three_qsort1(r+1, right);
}

void three_qsort2(int left, int right){
    if(left>=right) return;
    int l=left, r=right, mid=l+(r-l)/2;
    int i=l;
    while(i<=r){
        if(event[i].end_hour<event[mid].end_hour)  swap(&event[i++], &event[l++]);
        else if(event[i].end_hour>event[mid].end_hour)  swap(&event[i], &event[r--]);
        else i++;
    }
    three_qsort2(left, l-1);
    three_qsort2(r+1, right);
}

void printEvent(struct Event *event, int len){
    three_qsort1(0, len-1);

    int *arr, inx=0;
    arr=(int*)malloc(sizeof(int)*len);
    for(int i=0; i<len; i++) arr[i]=0;
    for(int i=1; i<len; i++){
        if(event[i].begin_hour!=event[i-1].begin_hour) arr[inx++]=i-1;
        else continue;
    }
    arr[inx]=len-1;

    for(int i=0; i<=inx; i++){
        if(i==0 && arr[i]!=0) three_qsort2(0, arr[i]);
        else if(i>0 && arr[i]-arr[i-1]>1) three_qsort2(arr[i-1]+1, arr[i]);
    }

    for(int i=0; i<len; i++) printf("%d %d\n", event[i].begin_hour, event[i].end_hour);
    free(arr);
}

int main(){
    init();
    printEvent(event, n);
    free(event);
    return 0;
}