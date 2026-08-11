#include <stdio.h>
#define MAX 1000


int maxHeap[MAX];
int maxSize = 0;

void maxSwap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxInsert(int value) {
    int i = maxSize;
    maxHeap[maxSize++] = value;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (maxHeap[parent] >= maxHeap[i])
            break;
        maxSwap(&maxHeap[parent], &maxHeap[i]);
        i = parent;
    }
}

int maxRemove() {
    int result = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxSize && maxHeap[left] > maxHeap[largest]) {
            largest = left;
        }
        if (right < maxSize && maxHeap[right] > maxHeap[largest]) {
            largest = right;
        }
        if (largest == i)
            break;
        maxSwap(&maxHeap[i], &maxHeap[largest]);
        i = largest;
    }

    return result;
}
int maxTop() {
    return maxHeap[0];
}


int minHeap[MAX];
int minSize = 0;

void minSwap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minInsert(int value) {
    int i = minSize;
    minHeap[minSize++] = value;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (minHeap[parent] <= minHeap[i])
            break;
        minSwap(&minHeap[parent], &minHeap[i]);
        i = parent;
    }
}

int minRemove() {
    int result = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minSize && minHeap[left] < minHeap[smallest]) {
            smallest = left;
        }
        if (right < minSize && minHeap[right] < minHeap[smallest]) {
            smallest = right;
        }
        if (smallest == i)
            break;
        minSwap(&minHeap[i], &minHeap[smallest]);
        i = smallest;
    }
    return result;
}
int minTop() {
    return minHeap[0];
}


void insert(int num) {

    if (maxSize == 0) {
        maxInsert(num);
    }
    else if (num <= maxTop()) {
        maxInsert(num);
    }
    else {
        minInsert(num);
    }

    if (maxSize > minSize + 1) {
        int value = maxRemove();
        minInsert(value);
    }
    else if (minSize > maxSize + 1) {
        int value = minRemove();
        maxInsert(value);
    }
}

float getMedian() {
    if (maxSize == minSize) {
        return (maxTop() + minTop()) / 2.0;
    }
    if (maxSize > minSize) {
        return maxTop();
    }
    return minTop();
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the stream elements:\n");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(num);
        printf("After inserting %d, median = %.2f\n",
               num, getMedian());
    }

    return 0;
}