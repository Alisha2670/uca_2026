#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int arr[], int n, int i){
    while (1){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest == i)
            break;
        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void buildMaxHeap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapifyDown(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapifyDown(arr, i, 0);
    }
}

void generateRandom(int arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i] = n - i;
    }
}

int isSorted(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

int main(){
    int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int numSizes = 8;
    int randomArr[80000];
    int ascendingArr[80000];
    int descendingArr[80000];
    srand(time(NULL));
    printf("Size\tRandom(ms)\tAscending(ms)\tDescending(ms)\n");
    for (int j = 0; j < numSizes; j++) {
        int n = sizes[j];
        generateRandom(randomArr, n);
        generateAscending(ascendingArr, n);
        generateDescending(descendingArr, n);

        clock_t start = clock();
        heapSort(randomArr, n);
        clock_t end = clock();
        double randomTime =(double)(end - start) / CLOCKS_PER_SEC * 1000;

        start = clock();
        heapSort(ascendingArr, n);
        end = clock();
        double ascendingTime =(double)(end - start) / CLOCKS_PER_SEC * 1000;

        start = clock();
        heapSort(descendingArr, n);
        end = clock();
        double descendingTime =(double)(end - start) / CLOCKS_PER_SEC * 1000;

        printf("%d\t%.6f\t%.6f\t%.6f\n",n,randomTime,ascendingTime,descendingTime);
    }

    return 0;
}

