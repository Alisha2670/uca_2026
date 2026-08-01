#include <stdio.h>

int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {
    int x, n;
    printf("Enter x and n: ");
    scanf("%x %d", &x, &n);
    printf("0x%X\n", logicalShift(x, n));
    return 0;
}