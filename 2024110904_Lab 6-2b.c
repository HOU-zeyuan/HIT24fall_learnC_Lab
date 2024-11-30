#include <stdio.h>

int year, month, day, yearDay;
int *p_yearDay=&yearDay;
static int dayTab[2][13]={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void to_yearDay(int year, int month, int day, int *p_yearDay){
    int i;
    int leap=((year%4==0 && year%100!=0)) || (year%400==0);
    for(i=1; i<month; i++) *p_yearDay+=dayTab[leap][i];
    *p_yearDay+=day;
}

int main(){
    printf("Turn year, month, day into yearDay.\nyear month day: ");
    scanf("%d %d %d", &year, &month, &day);

    to_yearDay(year, month, day, p_yearDay);

    printf("%d年的%d月%d日是%d年的第%d天。\n", year, month, day, year, yearDay);
    return 0;
}