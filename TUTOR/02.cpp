#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>

struct Node{
    int value;
    Node *next;
};

//Tentuin dahulu lokasi data pertamanya.
Node *HEAD = NULL;
Node *TAIL = NULL;

//Mesen lokasi atau memori sesuai dengan ukuran Node.
Node* createNode(int value){
    // Malloc adalah function untuk memesan memori dengan ukuran yang sesuai.
    Node *new_nodes = (Node*) malloc(sizeof(Node));
    // Pesan memori untuk new nodes
    // Pointer newnodes --> (Tipe : Pointer Node) dengan ukuran (Node)

    // (*new_nodes).value = value;
    new_nodes->value = value;
    new_nodes->next = NULL;
    
    return new_nodes;
}

//Masukin data dari depan
void pushHead(int value){
    
    Node *temp = createNode(value);
    // if (HEAD == NULL)
    if(!HEAD){
        //Kalau belum ada data, maka data tersebut adalah data pertama dan terakhir.
        HEAD = TAIL = temp;
    }else{
        //Kalau sudah ada data yang pernah masuk
        temp->next = HEAD;
        HEAD = temp;
    }
}

//Masukin data dari belakang
void pushTail(int value){
    Node *temp = createNode(value);

    if(!HEAD){
        HEAD = TAIL = temp;
    }else {
        TAIL->next = temp;
        TAIL = temp;
    }
}

//Delete data paling depan;
void deleteHead(){
    if (!HEAD){
        // Kalau ga ada data, ya udah ga usah diapus lah datanya wkwokwowk.
        return;
    }else if(HEAD == TAIL){
        // Kalau data hanya ada satu, maka kedua data ke set jadi NULL
        HEAD = TAIL = NULL;
    }else {
        // Head yang lama, adalah head yang setelahnya.
        Node *temp = HEAD->next;

        // Lepaskan memori yang anda pesan sebelumnya.
        free(HEAD);
        HEAD = temp;
    }
}

void deleteTail(){
    if (!HEAD){
        // Kalau ga ada data, ya udah ga usah diapus lah datanya wkwokwowk.
        return;
    }else if(HEAD == TAIL){
        // Kalau data hanya ada satu, maka kedua data ke set jadi NULL
        HEAD = TAIL = NULL;
    }else {
        Node *temp = HEAD;
        while(temp->next != TAIL){
            temp = temp->next;
        }
        free(TAIL);
        temp->next = NULL;
        TAIL = temp;
    }
}

void viewData(){
    Node *curr = HEAD;

    while(curr){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    puts("");
}

int main(){
    pushHead(5);
    pushHead(7);
    pushHead(2);
    pushHead(9);
    pushTail(3);

    viewData();
    deleteHead();
    viewData();
    deleteTail();
    viewData();
    return 0;
}