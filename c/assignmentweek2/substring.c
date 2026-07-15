#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i, j;
    if (needle[0] == '\0')
        return 0;
    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') {
            return i;
        }
    }
    return -1;
}

int main() {
    char haystack[100];
    char needle[100];

    printf("Enter the main string (haystack): ");
    fgets(haystack, sizeof(haystack), stdin);

    printf("Enter the substring (needle): ");
    fgets(needle, sizeof(needle), stdin);
    int i = 0;
    while (haystack[i] != '\0') {
        if (haystack[i] == '\n') {
            haystack[i] = '\0';
            break;
        }
        i++;
    }
    i = 0;
    while (needle[i] != '\0') {
        if (needle[i] == '\n') {
            needle[i] = '\0';
            break;
        }
        i++;
    }

    int index = find_substring(haystack, needle);

    if (index != -1)
        printf("Substring found at index %d\n", index);
    else
        printf("Substring not found\n");

    return 0;
}