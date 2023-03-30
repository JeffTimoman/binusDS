#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next;
};

Node *HEAD = NULL;
Node *TAIL = NULL;

Node *createNode(int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->next = HEAD;
        HEAD = temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if (!HEAD){
        HEAD = TAIL = temp;
    }else {
        TAIL->next = temp;
        TAIL = temp;
    }
}

void viewData(){
    if (!HEAD){
        return;
    }else{
        Node *CURR = HEAD;
        while(CURR){
            printf("%d ", CURR->value);
            CURR = CURR->next;
        }
    }
}   

void popHead(){
    if (!HEAD){
        return;
    }else if (HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        Node *temp = HEAD;
        HEAD = HEAD->next;
        temp->next = NULL;
        free(temp);
    }
}

void popTail(){
    if (!HEAD){
        return;
    }else if (HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        Node *CURR = HEAD;
        while(CURR->next != TAIL){
            CURR = CURR->next;
        }
        CURR->next = NULL;
        free(TAIL);
        TAIL = CURR;
    }
}

int main(){
    pushHead(10);
    pushTail(20);
    pushTail(30);
    pushTail(40);

    viewData();
    return 0;
}