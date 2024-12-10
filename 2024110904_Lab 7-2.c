#include <stdio.h>

int temp[10], inx[10];

typedef struct Subject
{
    int mathScore;
    int physicsScore;
    int programmingScore;
} Subject;

typedef struct Student
{
    char *id;
    char *name;
    Subject sub;
} Student;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b, *b = t;
}

void three_qsort(int left, int right)
{
    if (left >= right)
        return;
    int l = left, r = right, mid = temp[l + (r - l) / 2];
    int i = left;
    while (i <= r)
    {
        if (temp[i] < mid)
            swap(&temp[i], &temp[l]), swap(&inx[i++], &inx[l++]);
        else if (temp[i] > mid)
            swap(&temp[i], &temp[r]), swap(&inx[i], &inx[r--]);
        else
            i++;
    }
    three_qsort(left, l - 1);
    three_qsort(r + 1, right);
}

void printMathScore(Student *stu, int len)
{
    for (int i = 0; i < len; i++)
        temp[i] = stu[i].sub.mathScore, inx[i] = i;

    three_qsort(0, len - 1);
    printf("Print mathScore:\n");
    for (int i = len - 1; i >= 0; i--)
        printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

void printPhysicsScore(Student *stu, int len)
{
    for (int i = 0; i < len; i++)
        temp[i] = stu[i].sub.physicsScore, inx[i] = i;
    three_qsort(0, len - 1);
    printf("Print physicsScore:\n");
    for (int i = len - 1; i >= 0; i--)
        printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

void printProgrammingScore(Student *stu, int len)
{
    for (int i = 0; i < len; i++)
        temp[i] = stu[i].sub.programmingScore, inx[i] = i;
    three_qsort(0, len - 1);
    printf("Print programmingScore:\n");
    for (int i = len - 1; i >= 0; i--)
        printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

int main()
{
    Subject Sub[10] = {{99, 100, 60}, {98, 88, 90}, {87, 100, 100}, {89, 88, 87}, {78, 90, 93}, {100, 100, 100}, {80, 94, 99}, {100, 88, 78}, {78, 77, 76}, {90, 90, 97}};
    Student Stu[10] = {{"20221101", "A", Sub[0]}, {"20221102", "B", Sub[1]}, {"20221103", "C", Sub[2]}, {"20221104", "D", Sub[3]}, {"20221105", "E", Sub[4]}, {"20221106", "F", Sub[5]}, {"20221107", "G", Sub[6]}, {"20221108", "H", Sub[7]}, {"20221109", "I", Sub[8]}, {"20221110", "J", Sub[9]}};
    printMathScore(Stu, 10);
    printPhysicsScore(Stu, 10);
    printProgrammingScore(Stu, 10);
    return 0;
}