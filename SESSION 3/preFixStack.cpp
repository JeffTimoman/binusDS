#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int value;
    Node *next;
}*TOP = NULL;

Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value){
    Node *temp = createNode(value);
    if(!TOP){
        TOP = temp;
    } else {
        temp->next = TOP;
        TOP = temp;
    }
}

void pop(){
    if(!TOP){
        return;
    } else if(!TOP->next){
        free(TOP);
        TOP = NULL;
    } else {
        Node *temp = TOP;
        TOP = TOP->next;
        temp->next = NULL;
        free(temp);
    }
}

void printStackRev(Node* curr = TOP){
    if(curr){
        printStackRev(curr->next);
        printf("%d ", curr->value);
    }
}

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    char string[100] = "+7-*65^32";

    for (int i = strlen(string)-1; i >= 0; i--){
        if (string[i] >= '0' && string[i] <= '9'){
            push(string[i] - '0');
        } else {
            int a = TOP->value;
            pop();
            int b = TOP->value;
            pop();
            switch (string[i]){
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '*':
                    push(a*b);
                    break;
                case '/':
                    push(a/b);
                    break;
                case '^':
                    push(pow(a,b));
                    break;
            }
        }
            // printStackRev();
            //puts();
    }

    printf("%d", TOP->value);
    return 0;
}