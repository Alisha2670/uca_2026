#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}