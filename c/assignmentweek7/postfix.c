#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluatePostfix(char expression[]) {
    int stack[50];
    int top = -1;
    char *token = strtok(expression, " ");
    while(token != NULL){
        if(token[0]>='0' && token[0]<='9'){
            stack[++top] = atoi(token);
        }
        else{
            int b=stack[top--];
            int a=stack[top--];
            switch(token[0]){
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;
            }
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}

int main() {
    char expression[] = "2 3 1 * + 9 -";
    int result = evaluatePostfix(expression);
    printf("%d\n", result);
    return 0;
}