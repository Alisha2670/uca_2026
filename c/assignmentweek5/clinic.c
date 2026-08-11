#include <stdio.h>

typedef struct {
    int population;
    int clinics;
    double load;
} Village;

void swap(Village* a, Village* b){
    Village temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyDown(Village heap[], int n, int i){
    while(1){
        int largest=i;
        int left= 2*i+1;
        int right=2*i+2;
        if(left<n && heap[left].load > heap[largest].load){
            largest=left;
        }
        if(right<n && heap[right].load > heap[largest].load){
            largest=right;
        }
        if(largest==i){
            break;
        }
        swap(&heap[i],&heap[largest]);
        i=largest;
    }
}


int main() {

    int n, k;

    printf("Enter number of villages: ");
    scanf("%d", &n);

    int population[n];

    printf("Enter population of each village:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &population[i]);
    }

    printf("Enter number of clinics: ");
    scanf("%d", &k);

    if (k < n) {
        printf("Invalid input: k must be >= n\n");
        return 0;
    }

    Village heap[n];
    for (int i = 0; i < n; i++) {

        heap[i].population = population[i];
        heap[i].clinics = 1;
        heap[i].load = (double)population[i];
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, n, i);
    }
    int extraClinics = k - n;

    for (int i = 0; i < extraClinics; i++) {
        heap[0].clinics++;
        heap[0].load =(double)heap[0].population / heap[0].clinics;
        heapifyDown(heap, n, 0);
    }
    printf("Minimum possible maximum load = %.2f\n",
           heap[0].load);

    return 0;
}