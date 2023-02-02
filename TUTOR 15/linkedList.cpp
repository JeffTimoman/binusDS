#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    //Data yang mau disimpan
    int age;
    //Simpan alamat sebelumnya
    Node *prev;

    //Simpan alamat setelahnya
    Node *next;
}*HEAD, *TAIL;


//Fungsi untuk membuat node baru
//return type: Node*
Node* createNode(int age){
    // Saya mau membuat sebuah pointer Node namanya newNode, dengan tipe (Node *) yang punya ukuran dari node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // Isi data dari newNode
    newNode->age = age;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Fungsi untuk menambahkan node di awal
void pushHead(int value){
    if (!HEAD){
        HEAD = TAIL = createNode(value);
    }else{
        Node* temp = createNode(value);
        temp->next = HEAD;
        HEAD->prev = temp;
        HEAD = temp;
    }
}

//Fungsi untuk menambahkan node di akhir
void pushTail(int value){
    //Apakah datanya sudah ada?
    // Kalo belum ada, maka buat node baru sebagai HEAD dan TAIL.
    if (!HEAD){
        HEAD = TAIL = createNode(value);
    }else{
        Node* temp = createNode(value);
        temp->prev = TAIL;
        TAIL->next = temp;
        TAIL = temp;
    }
}

//Misal : Data 3 Nama, Umur, NIM.
// --> Nama/Umur/NIM
void pushSort(int value){
    // Sort berdasarkan integer : 
    // 1. Cek apakah data sudah ada?
    // 2. Apakah data pertama lebih besar dari besar dari data yang mau dimasukkan?
    // 3. Apakah data terakhir lebih kecil dari data yang mau dimasukkan?
    // 4. Data berada ditengah2.
    if (!HEAD){
        HEAD = TAIL = createNode(value);
    }else if(HEAD -> age > value){
        pushHead(value);
    }else if(TAIL -> age < value){
        pushTail(value);
    }else{
        // 1 3 5 8 12
        // 9 
        // -> 1 3 5 8 9 12
        //Nyari 12
        Node *temp = createNode(value);
        Node *curr = HEAD;
        while (curr->age < value){
            curr = curr->next;
        }   
        //curr = yang value 12

        //Hubungkan 9 ke 12
        temp->next = curr;

        //Hubungkan 9 ke 8
        temp->prev = curr->prev;

        //Hubungkan 8 ke 9
        curr->prev->next = temp;

        //Hubungkan 12 ke 9
        curr->prev = temp;

        // Nyari 8
        // Node *curr = TAIL;
        // while (curr->age > value){
        //     curr = curr->prev;
        // }

    }
}

void popHead(){
    // Tiga cek :
    // 1. Cek apakah data ada?
    // 2. Cek apakah data hanya 1?
    // 3. Cek apakah data lebih dari 1?
    if (!HEAD){
        return;
    }else if(HEAD == TAIL){
        //DATAnya cuma 1
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        HEAD = HEAD->next;
        free(HEAD->prev);
        HEAD->prev = NULL;
        // 1 3 5 8 12
        // HEAD = 1 -> HEAD = 3
        // free(HEAD->prev) -> free(1)
        // HEAD->prev = 1 -> HEAD->prev = NULL;
        // 3 5 8 12
    }
}

void popTail(){
    // Tiga cek :
    // 1. Cek apakah data ada?
    // 2. Cek apakah data hanya 1?
    // 3. Cek apakah data lebih dari 1?
    if (!HEAD){
        return;
    }else if(HEAD == TAIL){
        //DATAnya cuma 1
        free(HEAD);
        HEAD = TAIL = NULL;
    }else{
        TAIL = TAIL->prev;
        free(TAIL->next);
        TAIL->next = NULL;
    }
}

void popSearch(int value){

}

void popAll(){
    while (HEAD){
        popHead();
    }
}

void printLinkedList(){
    Node *curr = HEAD;
    while (curr){
        printf("%d -> ", curr->age);
        curr = curr->next;
    }
    puts("NULL");
}

int main(){
    return 0;
}

//Mahasiswa (NIM, Umur, Nama)
// createNode, pushHead, pushTail, popHead, popTail;
// pushSortByNIM, pushSortByUmur, pushSortByNama;
// popSearchByNIM, popSearchByUmur, popSearchByNama;