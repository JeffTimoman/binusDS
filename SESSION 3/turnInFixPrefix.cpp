#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void reverseString(char str[]){
    int i = 0, j = strlen(str) -1;
    while (i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void turnInfixtoPrefix(char infix[], char prefix[]){
    int i = 0, j = 0;
    char stack[100];
    int top = -1;
    reverseString(infix);
    while (infix[i] != '\0'){
        if (isalpha(infix[i])){
            prefix[j] = infix[i];
            j++;
        }
        else if (infix[i] == ')'){
            top++;
            stack[top] = infix[i];
        }
        else if (infix[i] == '('){
            while (stack[top] != ')'){
                prefix[j] = stack[top];
                top--;
                j++;
            }
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            if (top == -1){
                top++;
                stack[top] = infix[i];
            }
            else{
                if (infix[i] == '^'){
                    top++;
                    stack[top] = infix[i];
                }
                else if (infix[i] == '*' || infix[i] == '/'){
                    if (stack[top] == '^'){
                        top++;
                        stack[top] = infix[i];
                    }
                    else{
                        while (stack[top] == '*' || stack[top] == '/'){
                            prefix[j] = stack[top];
                            top--;
                            j++;
                        }
                        top++;
                        stack[top] = infix[i];
                    }
                }
                else if (infix[i] == '+' || infix[i] == '-'){
                    if (stack[top] == '^' || stack[top] == '*' || stack[top] == '/'){
                        top++;
                        stack[top] = infix[i];
                    }
                    else{
                        while (stack[top] == '+' || stack[top] == '-'){
                            prefix[j] = stack[top];
                            top--;
                            j++;
                        }
                        top++;
                        stack[top] = infix[i];
                    }
                }
            }
        }
        i++;
    }

    while (top != -1){
        prefix[j] = stack[top];
        top--;
        j++;
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main(){
    // char infix[100] = "A+B-C*D^E/F*(G-H)";
    char infix[100] = "(A-B/D^E+(F*G))";
    char prefix[100];
    printf("Infix: %s\n", infix);
    turnInfixtoPrefix(infix, prefix);
    // printf("Infix: %s\n", infix);
    printf("Prefix: %s", prefix);
}