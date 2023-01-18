#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next;
};  

Node *HEAD = NULL, *TAIL = NULL;

Node* createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if (!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->next = HEAD;
        HEAD = temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        TAIL->next = temp;
        TAIL = temp;
    }
}

void deleteHead(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        HEAD = TAIL = NULL;
    }else{
        Node *temp = HEAD->next;
        free(HEAD);
        HEAD = temp;
    }
}

void deleteTail(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        HEAD = TAIL = NULL;
    }else{
        Node *temp = HEAD;
        while(temp->next != TAIL){
            temp = temp->next;
        }
        free(TAIL);
        TAIL = temp;
        TAIL->next = NULL;
    }
}

void printLinkedList(){
    Node *temp = HEAD;
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void popAll(){
    while(HEAD){
        deleteHead();
    }
}

void popSearch(int value){
    if(!HEAD){
        return;
    }else if(TAIL->value == value){
        deleteTail();
    }else if(HEAD->value == value){
        deleteHead();
    }else{
        Node *temp = HEAD;
        while(temp->next != NULL){
            if(temp->next->value == value){
                Node *del = temp->next;
                // temp->next = del->next;
                temp->next = temp->next->next;
                free(del);
                return;
            }else{
                temp = temp->next;
            }
        }
    }
}

int main(){
    pushHead(5);
    pushTail(7);
    pushHead(3);
    pushTail(7);
    pushTail(9);

    popSearch(7);
    printLinkedList();
    return 0;
}