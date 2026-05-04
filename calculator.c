#include <stdio.h>

double addition (double a, double b);
double subtraction (double a, double b);
double multiplication (double a, double b);
double division (double a, double b);

int main () {

    double num;
    char operator;
    double result;

    printf("Enter a number: ");
    scanf("%lf", &num);

    while(1) {
        printf("Enter an operator(+, -, *, /) or (=) to finish the program: ");
        scanf(" %c", &operator);
        
        char next = getchar();

        if(next != '\n') {
            while(getchar() != '\n');
            printf("Invalid operator.\n");
            continue;
        }

        if(operator == '=') {
            break;
        }

        double second_num;

        printf("Enter a second number: ");
        scanf("%lf", &second_num);

        switch(operator){
            case '+': 
                result = addition(num, second_num);
                break;
            case '-':
                result = subtraction(num, second_num);
                break;
            case '*':
                result = multiplication(num, second_num);
                break;
            case '/':
                result = division(num, second_num);
                break;
            default:
                printf("Invalid operator.\n");
        }

        num = result;

    }

    if (result == (int) result) {
        printf("Result: %.0lf\n", result);
    } else 
        {printf("Result: %.2lf\n", result);
    }


    return 0;
}

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication (double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}