#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

char calendar[9][38], transformed_year[5];
char months[12][10] = {"  January", " February", "    March", "    April", "      May", "     June", "     July", "   August", "September", "  October", " November", " December"};
char week[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
char day[31][3] = {" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
// 为了使用strncpy函数，将months、week、day数组各行长度统一
void transform_year(int y) // 将年份由整数转化为字符串,以方便使用strncpy函数{
    int index1 = 3;
    while (y > 0){
        transformed_year[index1] = y % 10 + '0';
        y = y / 10;
        index1--;
    }
}

void calendar_frame(int m, int y){ // 生成月历前三行
    if (m >= 1 && m <= 12) strncpy(calendar[0] + 10, months[m - 1], 9); // 将月份复制到月历第一行
    else printf("Invalid month\n");

    if (y < 1800) printf("Invalid year\n");
    else{
        transform_year(y);
        strncpy(calendar[0] + 20, transformed_year, 4);
    } // 将年份复制到月历第一行

    for (int i = 0; i < 38; i++) calendar[1][i] = '-';
    for (int i = 2, j = 0; i < 38, j < 7; i += 5, j++) strncpy(calendar[2] + i, week[j], 3); // 将星期几复制到月历第二行
}

int judge_year(int y){ // 闰年判断
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
    else return 0;
}

int judge_month(int m, int y){ // 每月天数判断
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else if (m == 2) return (28 + judge_year(y));
    else return 0;
}

int judge_day(int y, int m){ // 判断某年某月第一天是星期几
    int sum = 0;
    for (int i = 1800; i < y; i++) sum += (365 + judge_year(i));
    for (int i = 1; i <= m - 1; i++) sum += judge_month(i, y);
    return (sum + 3) % 7;
}

int main(){   
    int year;
    printf("Please input the year: ");
    scanf("%d", &year);
    int month;
    printf("Please input the month: ");
    scanf("%d", &month);

    for (int i = 0; i < 9; i++) for (int j = 0; j < 38; j++) calendar[i][j] = ' '; // 初始化月历
    calendar_frame(month, year);

    int x = 2 + 5 * (judge_day(year, month)), y = 3;
    for (int i = 0; i < judge_month(month, year); i++){ // 输入日期
        strncpy(calendar[y] + x, day[i], 2);
        if (x == 32) y++, x = 2;
        else x += 5;
    }

    printf("The output is: \n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 38; j++) printf("%c", calendar[i][j]);
        printf("\n");
    }
    return 0;
}
