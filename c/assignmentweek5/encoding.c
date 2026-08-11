#include <stdio.h>
#include <string.h>

void base64Encode(char input[], char output[]) {

    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int len = strlen(input);
    int i = 0;
    int j = 0;

    while (i < len) {

        unsigned char a = input[i++];  
        unsigned char b = 0;
        unsigned char c = 0;

        int hasB = 0;
        int hasC = 0;

        if (i < len) {
            b = input[i++];
            hasB = 1;
        }

        if (i < len) {
            c = input[i++];
            hasC = 1;
        }

        int index1 = a >> 2;
        int index2 = ((a & 0x03) << 4) | (b >> 4);
        int index3 = ((b & 0x0F) << 2) | (c >> 6);
        int index4 = c & 0x3F;

        output[j++] = table[index1];
        output[j++] = table[index2];

        if (hasB){
            output[j++] = table[index3];
        }
        else{
            output[j++] = '=';
        }

        if (hasC){
            output[j++] = table[index4];
        }
        else{
            output[j++] = '=';
        }

    }

    output[j] = '\0';
}

int main() {

    char input[1000];
    char output[2000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    base64Encode(input, output);
    printf("Base64: %s\n", output);

    return 0;
}