#include <stdio.h>

int sumEvenFibBrute(int n) {
    int a = 1, b = 1;
    int sum = 0;
    while (b <= n) {
        if (b % 2 == 0)
            sum += b;
        int c = a + b;
        a = b;
        b = c;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sumEvenFibBrute(n));
    return 0;
}