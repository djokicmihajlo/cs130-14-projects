#include <stdio.h>

int main(void) {
    int a;
    int b;
    char c;
    int result;
    printf("Enter the first number:");
    scanf("%d", &a);
    printf("Enter the second number:");
    scanf("%d", &b);
    printf("Enter the operation (+,-,/,*)");
    scanf(" %c", &c);

    switch (c) {
        case '+':
            result = a + b;
            printf("Result is %d\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result is %d\n", result);

            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("Result is %d\n", result);
            } else {
                printf("Division by Zero\n");
            }
            break;
        case '*':
            result = a * b;
            printf("Result is %d\n", result);

            break;
        default:
            printf("Invalid Operation\n");
            break;
    }
    return 0;
}
