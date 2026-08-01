#include <stdio.h>

int bitXor(int x, int y) {
    return (~(~x & ~y)) & (~(x & y));
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("bitXor = %d\n", bitXor(x, y));
    return 0;
}