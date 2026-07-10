#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    clock_t start, end;
    double timeTaken;

    srand(time(NULL));

    
    generateRandom(arr, n);

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Random Array Time      : %.3f ms\n", timeTaken);

   
    generateAscending(arr, n);

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Ascending Array Time   : %.3f ms\n", timeTaken);

    
    generateDescending(arr, n);

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Descending Array Time  : %.3f ms\n", timeTaken);

    return 0;
}