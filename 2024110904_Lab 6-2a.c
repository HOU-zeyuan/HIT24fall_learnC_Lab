#include <stdio.h>

int year, yearDay, month, day;
int *pMonth=&month, *pDay=&day;
static int dayTab[2][13]={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void Monthday(int year, int yearDay, int *pMonth, int *pDay){
    int i;
    int leap=((year%4==0) && (year%100!=0)) || (year%400==0);
    for(i=1; yearDay>dayTab[leap][i]; i++) yearDay-=dayTab[leap][i];
    *pMonth=i, *pDay=yearDay;
}

int main(){
    printf("Turn year, yearDay into month, day.\nyear yearDay: ");
    scanf("%d %d", &year, &yearDay);
    
    Monthday(year, yearDay, pMonth, pDay);

    printf("month: %d day: %d\n", month, day);
    return 0;
}