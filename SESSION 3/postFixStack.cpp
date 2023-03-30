#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    Node *next;
} *TOP = NULL;

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

void printStack(){
    Node *curr = TOP;
    while(curr){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void printStackRev(Node* curr){
    if(curr){
        printStackRev(curr->next);
        printf("%d ", curr->value);
    }
}

int main(){
    char input[100] = "4652-*3/+";
    if (strlen(input) == 0){
        printf("Invalid input");
        return 0;
    }else{
        for(int i = 0; i < strlen(input); i++){
            if(input[i] >= '0' && input[i] <= '9'){
                push(input[i] - '0');
            } else {
                int a = TOP->value;
                pop();
                int b = TOP->value;
                pop();
                switch(input[i]){
                    case '+':
                        push(a + b);
                        break;
                    case '-':
                        push(a - b);
                        break;
                    case '*':
                        push(a * b);
                        break;
                    case '/':
                        push(a / b);
                        break;
                }
            }
            printStackRev(TOP);
            puts("");
        }
        printf("%d", TOP->value);
    }
    return 0;
}

