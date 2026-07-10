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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Random Array Time      : %.3f ms\n", timeTaken);

    generateAscending(arr, n);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Ascending Array Time   : %.3f ms\n", timeTaken);

    generateDescending(arr, n);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Descending Array Time  : %.3f ms\n", timeTaken);

    return 0;
}