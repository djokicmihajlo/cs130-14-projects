#include <stdio.h>

int main(void) {
    double a;
    double b;
    char c;
    double result;
    printf("Enter the first number:");
    scanf("%lf", &a);
    printf("Enter the second number:");
    scanf("%lf", &b);
    printf("Enter the operation (+,-,/,*)");
    scanf(" %c", &c);

    switch (c) {
        case '+':
            result = a + b;
            printf("Result is %lf\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result is %lf\n", result);

            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("Result is %lf\n", result);
            } else {
                printf("Division by Zero\n");
            }
            break;
        case '*':
            result = a * b;
            printf("Result is %lf\n", result);

            break;
        default:
            printf("Invalid Operation\n");
            break;
    }
    return 0;
}
