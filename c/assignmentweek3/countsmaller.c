#include <stdio.h>

#define MAX 100000

int nums[MAX];
int indexArr[MAX];
int tempNums[MAX];
int tempIndex[MAX];
int answer[MAX];

void merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;
    while (i <= mid && j <= right){
        if (nums[j] < nums[i]){
            tempNums[k] = nums[j];
            tempIndex[k] = indexArr[j];
            rightCount++;
            j++;
        }
        else{
            answer[indexArr[i]] += rightCount;
            tempNums[k] = nums[i];
            tempIndex[k] = indexArr[i];
            i++;
        }
        k++;
    }

    while (i <= mid){
        answer[indexArr[i]] += rightCount;
        tempNums[k] = nums[i];
        tempIndex[k] = indexArr[i];
        i++;
        k++;
    }

    while (j <= right){
        tempNums[k] = nums[j];
        tempIndex[k] = indexArr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++){
        nums[i] = tempNums[i];
        indexArr[i] = tempIndex[i];
    }
}

void mergeSort(int left, int right){
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
        indexArr[i] = i;
        answer[i] = 0;
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}