#include <stdio.h>
#include <stdlib.h>

struct Node{
    Node *prev;
    int value;
    Node *next;
};

Node *HEAD = NULL;
Node *TAIL = NULL;

Node* createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
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

void pushMid(int value, int index){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        Node *curr = HEAD;
        for(int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        TAIL->next = temp;
        temp->prev = TAIL;
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
        Node *temp = HEAD->next;
        temp->prev = NULL;
        free(HEAD);
        HEAD = temp;
    }
}

void deleteTail(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        Node *temp = TAIL->prev;
        temp->next = NULL;
        free(TAIL);
        TAIL = temp;
    }
}

void printLinkedList(){
    Node *curr = HEAD;
    while(curr){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    pushTail(1);
    pushHead(5);
    pushHead(7);
    pushHead(9);
    pushHead(11);
    pushHead(13);
    printLinkedList();
    pushMid(3, 2);
    printLinkedList();

    return 0;

}