#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node* createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push_head(int value){
    if (!head){
        head = tail = createNode(value);
    } else {
        Node *temp = createNode(value);
        temp->next = head;
        head = temp;
    }
}

void delete_head(){
    if (!head){
        return;
    } else if (head == tail){
        free(head);
        head = tail = NULL;
    } else {
        Node *temp = head->next;
        free(head);
        head = temp;
    }
}

void delete_tail(){

    //Buat cek apakah udah ada data di dalam linked list 
    if (!head){
        return;
    //Buat ngecek apakah head sama dengan tail (cmn ada 1 data, kalo dihapus berarti ilang semua)
    } else if (head == tail){
        free(head);
        head = tail = NULL;
    //Buat ngecek apakah head dan tail beda (ada lebih dari 1 data, kalo dihapus tail, tailnya jadi head)
    } else {
        Node *curr = head;
        while (curr->next != tail){
            curr = curr->next;
        }
        free(tail);
        tail = curr;
        tail->next = NULL;
    }
}

void view(){
    Node *curr = head;
    while (curr){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    push_head(1);
    push_head(2);
    push_head(3);
    push_head(4);

    view();
    delete_head();
    view();
    delete_tail();
    view();
    return 0;
}