#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
void generateFibonacci(int n) {
    int a = 0, b = 1, fib, i;
    printf("Fibonacci Series using Stack:\n");
    printf("%d %d ", a, b);
    push(a);
    push(b);
    for (i = 2; i < n; i++) {
        fib = a + b;
        push(fib);
        printf("%d ", fib);
        a = b;
        b = fib;
    }
}
int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
    generateFibonacci(n);
    return 0;
}


