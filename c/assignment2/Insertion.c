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

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Random Array Time      : %.3f ms\n", timeTaken);

    generateAscending(arr, n);

    start = clock();
    insertionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Ascending Array Time   : %.3f ms\n", timeTaken);

    generateDescending(arr, n);

    start = clock();
    insertionSort(arr, n);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Descending Array Time  : %.3f ms\n", timeTaken);

    return 0;
}