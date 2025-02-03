#include <stdio.h>

void add(float a, float b) {
    printf("Result: %.2f\n", a + b);
}

void subtract(float a, float b) {
    printf("Result: %.2f\n", a - b);
}

void multiply(float a, float b) {
    printf("Result: %.2f\n", a * b);
}

void divide(float a, float b) {
    if (b != 0) {
        printf("Result: %.2f\n", a / b);
    } else {
        printf("Error: Division by zero\n");
    }
}

int main() {
    float num1, num2;
    int choice;

    while (1) {
        printf("\nSimple Calculator\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*INPUT & OUTPUT:

Simple Calculator
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice: 1
Enter two numbers: 2 3
Result: 5.00

Simple Calculator
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice: 2
Enter two numbers: 2 3
Result: -1.00

Simple Calculator
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice: 3
Enter two numbers: 
2  3
Result: 6.00

Simple Calculator
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice: 4
Enter two numbers: 2 3
Result: 0.67

Simple Calculator
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice: 5


=== Code Execution Successful === */
