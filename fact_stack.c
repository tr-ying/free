#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int factorialUsingStack(int n) {
    if (n < 0) {
        printf("Invalid input for factorial\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0 || n == 1)
        return 1;

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        push(i);
    }

    while (top != -1) {
        result *= pop();
    }

    return result;
}

int main() {
    int num;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    printf("Factorial of %d using stack: %d\n", num, factorialUsingStack(num));

    return 0;
}
