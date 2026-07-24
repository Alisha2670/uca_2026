#include <stdio.h>
#define MAX 100000

int temp[MAX];

int merge(int arr[],int low, int mid, int high){
    int count=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && (long long)arr[i]> 2LL*arr[j]){
            j++;
        }
        count+= j-(mid+1);
    }
    int i=low;
    j=mid+1;
    int k= low;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
    return count;

}

int mergeSort(int arr[],int low,int high){
    if(low>=high){
        return 0;
    }
    int mid=low+(high-low)/2;
    int count=0;
    count += mergeSort(arr,low,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}

int main(){
    int n;
    int arr[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",mergeSort(arr,0,n-1));
    return 0;
}