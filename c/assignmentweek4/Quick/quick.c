#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}


void quickSelect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k)
            return;
        else if (pivotIndex > k)
            quickSelect(arr, low, pivotIndex - 1, k);
        else
            quickSelect(arr, pivotIndex + 1, high, k);
    }
}


void printKSmallest(int arr[], int k)
{
    printf("\nSmallest %d elements (any order):\n", k);
    for (int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    generateRandomArray(arr, n);
    printf("Enter value of K: ");
    scanf("%d", &k);
    if (k <= 0 || k > n)
    {
        printf("Invalid value of K.\n");
        free(arr);
        return 0;
    }
    clock_t start = clock();
    quickSelect(arr, 0, n - 1, k - 1);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printKSmallest(arr, k);
    printf("\nExecution Time = %.6f seconds\n", timeTaken);
    free(arr);
    return 0;
}