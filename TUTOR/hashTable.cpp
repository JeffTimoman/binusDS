#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

// "ALIN" (NODE), "OYIN" (NODE)
struct Node{
    int key;
    char value[100];
    Node *next;
};

// Linked List of Nodes
struct HashBucket{
    int dataCount;
    Node *HEAD;
    Node *TAIL;
};

// Hash Tables!
HashBucket hashTable[MAX];

// Ubah 
int stringToInt(char input[]){
    int len = strlen(input);
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += (int) input[i];
    }
    return sum;
}

// Pembuatan Key
int hashFunc(char input[]){
    int result = stringToInt(input);
    return result % MAX;
}

// Pembuatan Nodes
Node* createNode(char input[]){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = hashFunc(input);
    strcpy(newNode->value, input);
    newNode->next = NULL;
    return newNode;
}

// Push Data Into the Hash Table
void push(char input[]){
    Node *temp = createNode(input);

    if (hashTable[temp->key].HEAD == NULL){
        hashTable[temp->key].HEAD = hashTable[temp->key].TAIL = temp;
    }else{
        hashTable[temp->key].TAIL->next = temp;
        hashTable[temp->key].TAIL = temp;
    }
    hashTable[temp->key].dataCount++;
}

void search(char input[]){
    int key = hashFunc(input);
    Node *curr = hashTable[key].HEAD;

    while(curr){
        if (strcmp(curr->value, input) == 0){
            printf("%s, data has been found in box [%d]\n", input, key);
            return;
        }
        curr = curr->next;
    }

    printf("Data cannot be found!");
}

void view(){
    for (int i = 0; i < MAX; i++){
        printf("[%d] : ", i);
        Node *curr = hashTable[i].HEAD;
        while(curr){
            printf("%s -> ",curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void pop(char input[]){
    int key = hashFunc(input);
    Node *curr = hashTable[key].HEAD;
    Node *prev = NULL;

    while(curr){
        if (strcmp(curr->value, input) == 0){
            if (prev == NULL){
                hashTable[key].HEAD = curr->next;
            }else{
                prev->next = curr->next;
            }
            free(curr);
            hashTable[key].dataCount--;
            printf("%s, data has been deleted from box [%d]\n", input, key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Data cannot be found!");
}


int main(){
    push("OLINE");
    push("JEFF");
    push("ALIN");
    push("JEFF");
    view();
    search("JEFF");
    pop("JEFF");
    view();
    // view();
    return 0;
}