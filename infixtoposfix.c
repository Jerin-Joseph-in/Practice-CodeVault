#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


char s[50];
char E[100];
char item;
int top = -1, n, i;


void push(char item) {
    if (top == n - 1) {
        printf("Stack full\n");
    } else {
        s[top + 1] = item;
        top++;
    }
}


char pop() {
    if (top == -1) {
        printf("Stack empty\n");
        return '\0';
    } else {
        char temp = s[top];
        top--;
        return temp;
    }
}


int P(char sym) {
    switch (sym) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


void infix() {
    push('(');
    strcat(E, ")");
    for (i = 0; E[i] != '\0'; i++) {
        item = E[i];
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            printf("%c", item);
        } else if (item == '^' || item == '*' || item == '/' || item == '+' || item == '-') {
            while (top != -1 && P(s[top]) > P(item)) {
                printf("%c", pop());
            }
            push(item);
        } else if (item == ')') {
            while (top != -1 && s[top] != '(') {
                printf("%c", pop());
            }
            pop(); // remove '('
        } else {
            printf("Invalid expression\n");
            break;
        }
    }
}

void evaluatePostfix() {
    char expr[100];
    int stack[50], evalTop = -1;
    char ch;
    int val, a, b, result;

    printf("Enter postfix expression (no spaces, like AB+ or 23*5+): ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        if (isalpha(ch)) {
            printf("Enter value for %c: ", ch);
            scanf("%d", &val);
            evalTop++;
            stack[evalTop] = val;
        } else if (isdigit(ch)) {
            evalTop++;
            stack[evalTop] = ch - '0';
        } else {
            b = stack[evalTop];
            evalTop--;
            a = stack[evalTop];
            evalTop--;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
                default:
                    printf("Invalid operator %c\n", ch);
                    return;
            }

            evalTop++;
            stack[evalTop] = result;
        }
    }

    printf("Result = %d\n", stack[evalTop]);
}


int main() {
    int ch;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Infix to Postfix Conversion\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                top = -1; // reset stack
                printf("Enter size of expression: ");
                scanf("%d", &n);
                printf("Enter infix expression: ");
                scanf("%s", E);
                printf("Postfix expression is: ");
                infix();
                printf("\n");
                break;

            case 2:
                evaluatePostfix();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
