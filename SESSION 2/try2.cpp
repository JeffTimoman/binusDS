#include <stdio.h>
#include <stdlib.h>

struct Node{
    Node *prev;
    int value;
    Node *next;
};

Node *HEAD = NULL, *TAIL = NULL;

Node* createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    return new_node;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->next = HEAD;
        HEAD->prev = temp;
        HEAD = temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->prev = TAIL;
        TAIL->next = temp;
        TAIL = temp;
    }
}

void deleteHead(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        HEAD = HEAD->next;
        free(HEAD->prev);
        HEAD->prev = NULL;
    }
}

void deleteTail(){
    if (!HEAD){
        return;
    }else if(HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        TAIL = TAIL->prev;
        free(TAIL->next);
        TAIL->next = NULL;
    }
}

void printFromHead(){
    Node *temp = HEAD;
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void printFromTail(){
    Node *temp = TAIL;
    while(temp){
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    pushHead(2);
    pushTail(3);
    pushTail(6);
    pushHead(9);

    printFromHead();
    deleteTail();
    printFromHead();
    return 0;
}