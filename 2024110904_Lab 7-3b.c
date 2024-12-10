#include <stdio.h>
#include <stdlib.h>

int n, judge=0;

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
    int l=left, r=right, mid=event[l+(r-l)/2].begin_hour;
    int i=l;
    while(i<=r){
        if(event[i].begin_hour<mid)  swap(&event[i++], &event[l++]);
        else if(event[i].begin_hour>mid)  swap(&event[i], &event[r--]);
        else i++;
    }
    three_qsort1(left, l-1);
    three_qsort1(r+1, right);
}

void solve(Event *event, int len){
    three_qsort1(0, len-1);

    int latest=event[0].end_hour;
    for(int i=1; i<len; i++){
        if(event[i].begin_hour==event[i-1].begin_hour){
            judge=1;
            return;
        }
        if(i==len-1 && latest>event[i].begin_hour){
            judge=1;
            return;
        }
        latest=event[i].end_hour>latest?event[i].end_hour:latest;
    }
}

int main(){
    init();
    solve(event, n);

    if(judge) printf("否");
    else printf("是");

    free(event);
    return 0;
}