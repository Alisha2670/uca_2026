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

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    selectionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Random Array Time      : %.3f ms\n", timeTaken);

    generateAscending(arr, n);

    start = clock();
    selectionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Ascending Array Time   : %.3f ms\n", timeTaken);

    generateDescending(arr, n);

    start = clock();
    selectionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Descending Array Time  : %.3f ms\n", timeTaken);

    return 0;
}