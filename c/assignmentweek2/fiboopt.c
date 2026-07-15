#include <stdio.h>

int sumEvenFibOptimized(int n) {
    if (n < 2)
        return 0;
    int sum = 0;
    int a = 2;
    int b = 8;
    while (a <= n) {
        sum += a;
        int c = 4 * b + a;
        a = b;
        b = c;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sumEvenFibOptimized(n));
    return 0;
}