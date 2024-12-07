#include <stdio.h>
#include <stdlib.h>

int n;
int *temp, *inx;

typedef struct Subject{
    int mathScore;
    int physicsScore;
    int programmingScore;
}Subject;

typedef struct Student{
    char *id;
    char *name;
    Subject sub;
}Student;

Student *student;

void init(){
    printf("How many studemts?\n");
    scanf("%d", &n);
    getchar();
    student=(Student*)malloc(n*sizeof(Student));
    printf("id name mathScore physicsScore programmingScore:\n");
    for(int i=0; i<n; i++){
        student[i].id=(char*)malloc(30*sizeof(char));
        student[i].name=(char*)malloc(50*sizeof(char));
        scanf("%s %s %d %d %d", student[i].id, student[i].name, &student[i].sub.mathScore, &student[i].sub.physicsScore, &student[i].sub.programmingScore);
    }
    temp=(int*)malloc(n*sizeof(int));
    inx=(int*)malloc(n*sizeof(int));
}

void swap(int *a, int *b){
    int t=*a;
    *a=*b, *b=t;
}

void three_qsort(int left, int right){
    if(left>=right) return;
    int l=left, r=right, mid=l+(r-l)/2;
    int i=l;
    while(i<=r){
        if(temp[i]<temp[mid]) swap(&temp[i], &temp[l]), swap(&inx[i++], &inx[l++]);
        else if(temp[i]>temp[mid]) swap(&temp[i], &temp[r]), swap(&inx[i], &inx[r--]);
        else i++;
    }
    three_qsort(left, l-1);
    three_qsort(r+1, right);
}

void printMathScore(struct Student *stu, int len){
    for(int i=0; i<len; i++) temp[i]=stu[i].sub.mathScore, inx[i]=i;
    three_qsort(0, len-1);
    printf("Print mathScore:\n");
    for(int i=len-1; i>=0; i--) printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

void printPhysicsScore(struct Student *stu, int len){
    for(int i=0; i<len; i++) temp[i]=stu[i].sub.physicsScore, inx[i]=i;
    three_qsort(0, len-1);
    printf("Print physicsScore:\n");
    for(int i=len-1; i>=0; i--) printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

void printProgrammingScore(struct Student *stu, int len){
    for(int i=0; i<len; i++) temp[i]=stu[i].sub.programmingScore, inx[i]=i;
    three_qsort(0, len-1);
    printf("Print programmingScore:\n");
    for(int i=len-1; i>=0; i--) printf("%s %s %d\n", stu[inx[i]].id, stu[inx[i]].name, temp[i]);
}

void free_arr(){
    for(int i=0; i<n; i++) free(student[i].name), free(student[i].id);
    free(student), free(temp), free(inx);
}

int main(){
    init();
    printMathScore(student, n);
    printPhysicsScore(student, n);
    printProgrammingScore(student, n);
    free_arr();
    return 0;
}