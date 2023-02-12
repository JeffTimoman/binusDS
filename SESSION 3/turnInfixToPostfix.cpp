#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void turnInfixIntoPostfix(char infixString[], char postfixString[]){
    char OperandStack[1000];
    int postfixIndex = 0;
    int operandStackIndex = 0;
    
    for (int i = 0; i < strlen(infixString); i++){
        if ((infixString[i] >= '0' && infixString[i] <= '9')||(infixString[i] >= 'A' && infixString[i] <= 'Z')||(infixString[i] >= 'a' && infixString[i] <= 'z')){
            postfixString[postfixIndex++] = infixString[i];
        } else if (infixString[i] == '('){
            OperandStack[operandStackIndex++] = infixString[i];
        } else if (infixString[i] == ')'){
            while (OperandStack[operandStackIndex-1] != '('){
                postfixString[postfixIndex++] = OperandStack[--operandStackIndex];
            }
            operandStackIndex--;
        } else if (infixString[i] == '+' || infixString[i] == '-'){
            while (operandStackIndex > 0 && OperandStack[operandStackIndex-1] != '('){
                postfixString[postfixIndex++] = OperandStack[--operandStackIndex];
            }
            OperandStack[operandStackIndex++] = infixString[i];
        } else if (infixString[i] == '*' || infixString[i] == '/'){
            while (operandStackIndex > 0 && (OperandStack[operandStackIndex-1] == '*' || OperandStack[operandStackIndex-1] == '/')){
                postfixString[postfixIndex++] = OperandStack[--operandStackIndex];
            }
            OperandStack[operandStackIndex++] = infixString[i];
        }
    }

    while (operandStackIndex > 0){
        postfixString[postfixIndex++] = OperandStack[--operandStackIndex];
    }
    postfixString[postfixIndex] = '\0';
}

int main(){
    // char infixString[100] = "4+6*(5-2)/3";
    // char infixString[100] = "A+B-C*D^E/F*(G-H)";
    char infixString[100] = "(A+B*C)*D+E*F";
    char postfixString[100];
    turnInfixIntoPostfix(infixString, postfixString);

    printf("%s", postfixString);
    return 0;
}