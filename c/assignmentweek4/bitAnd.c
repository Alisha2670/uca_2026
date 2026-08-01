#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("bitAnd = %d\n", bitAnd(x, y));
    return 0;
}