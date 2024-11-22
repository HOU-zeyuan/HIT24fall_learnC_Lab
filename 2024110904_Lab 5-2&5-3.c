#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200000

float time_selectionSort, time_bubbleSort, time_insertSort, time_quickSort, time_mergeSort, time_heapSort;
int *test_arr;

void generate_arr(){
    for(int i=0; i<SIZE; i++) test_arr[i]=rand()%SIZE;
}

void swap_num(int *a, int *b){
    int temp=*a;
    *a=*b, *b=temp;
}

void selectionSort(){
    generate_arr();
    clock_t start=clock();

    for(int i=0; i<SIZE-1; i++){
        int min=i;
        for(int j=i+1; j<SIZE; j++){
            if(test_arr[j]<test_arr[min]) min=j;
        }
        swap_num(&test_arr[i], &test_arr[min]);
    }

    time_selectionSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

void bubbleSort(){
    generate_arr();
    clock_t start=clock();

    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(test_arr[j]>test_arr[j+1]) swap_num(&test_arr[j], &test_arr[j+1]);
        }
    }

    time_bubbleSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

void insertSort(){
    generate_arr();
    clock_t start=clock();

    for(int i=1; i<SIZE; i++){
        int temp=test_arr[i];
        int j=i-1;
        while(j>=0 && test_arr[j]>temp) test_arr[j+1]=test_arr[j], j--;
        test_arr[j+1]=temp;
    }

    time_insertSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

void quick_Sort(int left, int right){
    if(left>=right) return;

    srand(time(NULL));
    int l=left, r=right;
    int pivot=test_arr[rand()%(r-l+1)+l];
    
    while(l<=r){
        while(test_arr[l]<pivot) l++;
        while(test_arr[r]>pivot) r--;

       if(l<=r) swap_num(&test_arr[l], &test_arr[r]), l++, r--;
    }
    
    quick_Sort(left, r);
    quick_Sort(l, right);
}

void quickSort(){
    generate_arr();
    clock_t start=clock();

    quick_Sort(0, SIZE-1);

    time_quickSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

void merge_Sort(int left, int right){
    if(left>=right) return;

    int mid=left+(right-left)/2;
    merge_Sort(left, mid);
    merge_Sort(mid+1, right);

    int i=left, j=mid+1, k=0;
    int *temp=(int*)malloc((right-left+1)*sizeof(int));
    while(i<=mid && j<=right){
        if(test_arr[i]>test_arr[j]) temp[k++]=test_arr[j++];
        else temp[k++]=test_arr[i++];
    }
    while(i<=mid) temp[k++]=test_arr[i++];
    while(j<=right) temp[k++]=test_arr[j++];

    for(int i=0; i<right-left+1; i++) test_arr[left+i]=temp[i];
    free(temp);
}

void mergeSort(){
    generate_arr();
    clock_t start=clock();

    merge_Sort(0, SIZE-1);

    time_mergeSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

void heapify(int n, int index){
    int left=index*2+1, right=index*2+2, largest=index;
    if(left<n && test_arr[left]>test_arr[largest]) largest=left;
    if(right<n && test_arr[right]>test_arr[largest]) largest=right;

    if(largest!=index){
        swap_num(&test_arr[index], &test_arr[largest]);
        heapify(n, largest);
    }
}

void heapSort(){
    generate_arr();
    clock_t start=clock();

    for(int i=SIZE/2-1; i>=0; i--) heapify(SIZE, i);
    for(int i=SIZE-1; i>=0; i--){
        swap_num(&test_arr[0], &test_arr[i]);
        heapify(i, 0);
    }

    time_heapSort=(float)(clock()-start)/CLOCKS_PER_SEC;
}

int main(){
    srand(time(NULL));
    test_arr=(int*)malloc(sizeof(int)*SIZE);

    printf("Data size: %d\n", SIZE);
    selectionSort();
    printf("selectionSort uses %.3f seconds!\n", time_selectionSort);
    bubbleSort();
    printf("bubbleSort uses %.3f seconds!\n", time_bubbleSort);
    insertSort();
    printf("insertionSort uses %.3f seconds!\n", time_insertSort);
    quickSort();
    printf("quickSort uses %.3f seconds!\n", time_quickSort);
    mergeSort();
    printf("mergeSort uses %.3f seconds!\n", time_mergeSort);
    heapSort();
    printf("heapSort uses %.3f seconds!\n", time_heapSort);

    free(test_arr);
    return 0;
}