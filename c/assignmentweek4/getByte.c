#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;
    printf("Enter x and n:");
    scanf("%x %d", &x, &n);
    printf("0x%x\n", getByte(x, n));
    return 0;
}