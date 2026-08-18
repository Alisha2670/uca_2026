#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size){
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void heapify(void *arr, int n, int i, size_t size, int (*compare)(const void *, const void *)){
    while (1){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n &&compare((char *)arr + left * size, (char *)arr + largest * size) > 0){
            largest = left;
        }

        if (right < n &&compare((char *)arr + right * size, (char *)arr + largest * size) > 0){
            largest = right;
        }

        if (largest == i){
            break;
        }

        swap((char *)arr + i * size, (char *)arr + largest * size, size);
        i = largest;
    }
}

void heapSort(void *arr, int n, size_t size, int (*compare)(const void *, const void *)){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, size, compare);
    }

    for (int i = n - 1; i > 0; i--){
        swap((char *)arr,(char *)arr + i * size,size);
        heapify(arr, i, 0, size, compare);
    }
}

int compareInt(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x > y){
        return 1;
    }
    if (x < y){
        return -1;
    }
    return 0;
}

int compareFloat(const void *a, const void *b){
    float x = *(const float *)a;
    float y = *(const float *)b;
    if (x > y){
        return 1;
    }
    if (x < y){
        return -1;
    }
    return 0;
}

int compareDouble(const void *a, const void *b){
    double x = *(const double *)a;
    double y = *(const double *)b;
    if (x > y){
        return 1;
    }
    if (x < y){
        return -1;
    }
    return 0;
}

int compareChar(const void *a, const void *b){
    char x = *(const char *)a;
    char y = *(const char *)b;
    if (x > y){
        return 1;
    }
    if (x < y){
        return -1;
    }
    return 0;
}

int main(){
    int arr[] = {40, 10, 30, 50, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    printf("Sorted integers: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    float numbers[] = {4.5, 1.2, 8.3, 2.1, 6.7};
    int m = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, m, sizeof(float), compareFloat);

    printf("Sorted floats: ");
    for (int i = 0; i < m; i++){
        printf("%.2f ", numbers[i]);
    }
    printf("\n");


    double values[] = {9.87, 2.34, 7.65, 1.23, 5.43};
    int p = sizeof(values) / sizeof(values[0]);

    heapSort(values, p, sizeof(double), compareDouble);

    printf("Sorted doubles: ");
    for (int i = 0; i < p; i++){
        printf("%.2lf ", values[i]);
    }
    printf("\n");


    char letters[] = {'Z', 'A', 'M', 'C', 'B'};
    int q = sizeof(letters) / sizeof(letters[0]);

    heapSort(letters, q, sizeof(char), compareChar);

    printf("Sorted characters: ");
    for (int i = 0; i < q; i++){
        printf("%c ", letters[i]);
    }
    printf("\n");


    return 0;
}