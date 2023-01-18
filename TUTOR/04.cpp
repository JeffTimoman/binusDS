#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    Node *prev;
    int value;
    Node *next;
};  

// head dan tail adalah pointer yang menunjuk ke node pertama dan terakhir
// yang disimpan dalam head dan teail adalah alamat dari node pertama dan terakhir
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
    
    //If there is no data, then the data is the first and last data.
    if(!HEAD){
        HEAD = TAIL = temp;
    }else {
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
        TAIL->next = temp;
        temp->prev = TAIL;
        TAIL = temp;
    }
}

void pushMiddle(int value, int index){
    if (!HEAD){
        return;
    }else{
        Node *temp = createNode(value);
        Node *curr = HEAD;
        for(int i = 0; i < index - 1; i++){
            // if (curr->next == NULL), .
            if (!curr->next){
                return;
            }
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
    }
}

void pushSort(int value){
    Node *temp = createNode(value);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        Node *curr = HEAD;
        while(curr && curr->value < value){
            curr = curr->next;
        }
        if(curr == HEAD){
            pushHead(value);
        }else if(curr == NULL){
            pushTail(value);
        }else{
            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;
        }
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

void deletemiddle(int index){
    if(!HEAD){
        return;
    }else{
        Node *curr = HEAD;
        for(int i = 0; i < index - 1; i++){
            if(!curr->next){
                return;
            }
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next->prev = curr;
        free(temp);
    }
}

void deleteSearch(int value){
    if(!HEAD){
        return;
    }else if(HEAD->value == value){
        deleteHead();
    }else if(TAIL->value == value){
        deleteTail();
    }else{
        Node *curr = HEAD;
        while(curr){
            if (curr->value == value){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
                return;
            }else{
                curr = curr->next;
            }
        }
    }
}

void deleteSearch2(int value){
    if (!HEAD){
        return;
    }else if(HEAD->value == value){
        deleteHead();
    }else if(TAIL->value == value){
        deleteTail();
    }else{
        Node *curr = HEAD;
        while (curr->next != NULL){
            if (curr->next->value == value){
                Node *temp = curr->next;
                curr->next = temp->next;
                temp->next->prev = curr;
                free(temp);
                return;
            }else{
                curr = curr->next;
            }
        }
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
    pushSort(3);
    pushSort(7);
    pushSort(1);
    pushSort(5);
    pushSort(2);

    printLinkedList();
    return 0;
}