#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 97
// Penyimpanan per data yang mau disimpan.
struct Node{

    // Lokasi penyimpanan berdasarkan metode hashing
    int key;
    char string[100];

    //Single Linked List
    Node *next;
    // Node *prev;
};

// Array of Node
struct HashTable{
    int dataCount = 0;
    Node *HEAD;
    Node *TAIL;
};

// Array of linked list
HashTable hashTables[MAX];

// Fungsi hashing untuk mengubah string menjadi integer
int hashFunction(char string[]){
    int value = 0;
    // add all the sum of the ASCII value of each character
    // "alex" => "a" + "l" + "e" + "x" => 97 + 108 + 101 + 120 = 426
    for (int i = 0; i < strlen(string); i++){
        value += (int) string[i];
    }
    //426 % 97 = 38
    return value % MAX;
}

// Fungsi untuk membuat node baru : linked list
Node* createNode(char string[]){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = hashFunction(string);
    strcpy(newNode->string, string);
    newNode->next = NULL;
    return newNode;
}

void insertData(char string[]){
    // Langsung buat node;
    Node *temp = createNode(string);

    // 1. Linked list pada indeks key belum ada
    if (hashTables[temp->key].dataCount == 0){
        // Kalo data tidak ada maka buat linked list baru
        hashTables[temp->key].HEAD = hashTables[temp->key].TAIL = temp;
    }else{
        //2. Linked list pada indeks key sudah ada
        // Masukkan data di akhir linked list
        // Tail ke next = temp;
        //1 5 9 12
        //      TAIL
        //      temp = 15
        // TAIL->next = temp (15);
        // TAIL = temp;
        //1 5 9 12 15
        hashTables[temp->key].TAIL->next = temp;
        //Tail di akhir data, temp merupakan data terakhir.
        hashTables[temp->key].TAIL = temp;
    }
}

// Search
// Delete 
// Print


int main(){
    // printf("%d", hashFunction("alex"));
    insertData("alex");
    return 0;
}