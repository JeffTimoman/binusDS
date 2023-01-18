#include <stdio.h>
#include <stdlib.h>

struct Node{
    Node *prev;
    int value;
    Node *next;
};

/*
Untuk menandakan ketika pertama kali kita membuat linked list, maka belum ada data  
yang dimasukkan, maka kita harus membuat head dan tail menjadi NULL
*/
Node *HEAD = NULL, *TAIL = NULL;
// Node *HEAD = NULL;

/* 
Fungsi create note untuk pesan memori dengan ukuran yang sesuai dengan Node
Ukuran node adalah sizeof(Node)
Fungsi malloc akan mengembalikan alamat dari memori yang telah dipesan
Node* didepan malloc menunjukkan bahwa fungsi ini akan mengembalikan pointer dari tipe Node
'Node *newNode' untuk menampung pointer yang telah.
*/
Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*
Fungsi pushHead untuk menambahkan node di depan
Jika head dan tail adalah NULL, maka kita akan membuat node baru dan menempatkan node tersebut di head dan tail
maksudnya : kalau data belum ada maka data pertama adalah data terakhir.
*/
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

/*
Fungsi pushTail untuk menambahkan node di belakang
Jika head dan tail adalah NULL, maka kita akan membuat node baru dan menempatkan node tersebut di head dan tail
maksudnya : kalau data belum ada maka data pertama adalah data terakhir.
*/
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

/*
Fungsi pushSort untuk menambahkan node dengan urutan yang sudah terurut
Jika head dan tail adalah NULL, maka kita akan membuat node baru dan menempatkan node tersebut di head dan tail
maksudnya : kalau data belum ada maka data pertama adalah data terakhir.

Jika head dan tail tidak NULL, maka kita akan mencari node yang memiliki value lebih besar dari value yang akan dimasukkan
Jika value yang akan dimasukkan lebih kecil dari value node pertama, maka kita akan memasukkan node tersebut di depan
Jika value yang akan dimasukkan lebih besar dari value node terakhir, maka kita akan memasukkan node tersebut di belakang
*/
void pushSort(int value){
    Node *temp = createNode(value);

    // Cek apakah head dan tail adalah NULL
    if(!HEAD){
        HEAD = TAIL = temp;
    }else if(value < HEAD->value){
        // Cek kalau value yang akan dimasukkan lebih kecil dari value node pertama
        pushHead(value);
    }else if(value > TAIL->value){
        // Cek kalau value yang akan dimasukkan lebih besar dari value node terakhir
        pushTail(value);
    }else{
        // Cek kalau value yang akan dimasukkan lebih besar dari value node pertama dan lebih kecil dari value node terakhir
        // Anggaplah data : 1, 3, 5, 8, 9
        // Jika value yang akan dimasukkan adalah 4, maka kita akan mencari node yang memiliki value lebih besar dari 4
        // Node yang memiliki value lebih besar dari 4 adalah 5
        // Maka kita akan memasukkan node 4 di depan node 5
        Node *curr = HEAD;
        while(curr && value > curr->value){
            curr = curr->next;
        }
        temp->prev = curr->prev;
        temp->next = curr;
        curr->prev->next = temp;
        curr->prev = temp;
    }
}

// Delete node di depan
void popHead(){
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

// Delete node di belakang
void popTail(){
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

// Delete semua node
void popAll(){
    while(HEAD){
        popHead();
    }
}


// Delete 'satu node' dengan value tertentu
void popSearch(int value){
    if(!HEAD){
        return;
    }else if(TAIL->value == value){
        popTail();
    }else if(HEAD->value == value){
        popHead();
    }else{
        Node *temp = HEAD;
        /*
        Jika value yang akan dihapus adalah 3, maka kita akan mencari node yang memiliki value 3
        Jika node yang memiliki value 3 ditemukan, maka kita akan menghapus node tersebut
        */
        while(temp->next != NULL){
            // Kenapa temp->next != NULL ? Karena kita akan menghapus node setelah node temp
            // Jika node temp adalah node terakhir, maka kita tidak bisa menghapus node setelah node temp
            // Karena node setelah node terakhir adalah NULL, bukan node, jadi kita perlu berhenti kalau indexnya ga dalam range.
            if(temp->next->value == value){
                Node *del = temp->next;
                temp->next = temp->next->next;
                free(del);
                return;
            }else{
                temp = temp->next;
            }
        }
    }
}

// Delete 'satu node' dengan index tertentu
void popIndex(int index){
    if(!HEAD){
        return;
    }else if(index == 0){
        // Jika index yang akan dihapus adalah 0, maka kita akan menghapus node di depan
        popHead();
    }else{
        Node *temp = HEAD;
        int i = 0;
        while(temp->next != NULL){
            if(i == index-1){
                Node *del = temp->next;
                temp->next = temp->next->next;
                free(del);
                return;
            }else{
                temp = temp->next;
                i++;
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
    pushSort(5);
    pushSort(1);
    pushSort(3);
    pushSort(9);
    pushSort(8);
    pushSort(4);
    pushSort(2);
    pushSort(7);

    printLinkedList();
    popSearch(3);
    printLinkedList();
    return 0;
}