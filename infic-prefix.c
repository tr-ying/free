#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    char x;
    int i = 0, j = 0;

    strrev(infix); a+b*(c-d)

    for(i = 0; infix[i] != '\0'; i++) {
        if(isalnum(infix[i]))
            prefix[j++] = infix[i];
        else if(infix[i] == ')')
            push(infix[i]);
        else if(infix[i] == '(') {
            while((x = pop()) != ')')
                prefix[j++] = x;
        } else {
            while(priority(stack[top]) >= priority(infix[i]))
                prefix[j++] = pop();
            push(infix[i]);
        }
    }

    while(top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';
    strrev(prefix); 
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

// input: a+b*(c-d)