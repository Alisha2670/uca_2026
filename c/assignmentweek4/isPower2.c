#include <stdio.h>

int isPower2(int x) {
    return !(x >> 31) & !!x & !(x & (x + ~0));
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("%d\n", isPower2(x));
    return 0;
}