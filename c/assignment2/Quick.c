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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Random Array Time      : %.3f ms\n", timeTaken);

    generateAscending(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Ascending Array Time   : %.3f ms\n", timeTaken);

    generateDescending(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Descending Array Time  : %.3f ms\n", timeTaken);

    return 0;
}