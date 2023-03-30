#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 7

struct Node{
    int key;
    char data[100];
    Node *next;
};

struct HashBucket{
    //To count the data count in the bucket, rather than traverse the linked list.
    int dataCount;
    Node *HEAD;
    Node *TAIL;
};

HashBucket hashTable[TABLE_SIZE];

int stringToInt(char str[]){
    int sum = 0;
    for(int i = 0; i < strlen(str); i++){
        sum += (int) str[i];
    }
    return sum;
}

// int stringToInt(char str[], int index){
//     if(index == strlen(str)){
//         return 0;
//     }
//     return str[index] + stringToInt(str, index + 1);
// }

int division(char str[]){
    return stringToInt(str) % TABLE_SIZE;
}

Node* create_node(char str[]){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = division(str);
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

void push(char str[]){
    Node *node = create_node(str);
    if (hashTable[node->key].HEAD == NULL){
        hashTable[node->key].HEAD = hashTable[node->key].TAIL = node;
    }else{
        hashTable[node->key].TAIL->next = node;
        hashTable[node->key].TAIL = node;
    }
    hashTable[node->key].dataCount++;
}

void del(char str[]){
    
}

// void view(){
//     for(int i = 0; i < TABLE_SIZE; i++){
//         HashBucket HB = hashTable[i];
//         if(HB.HEAD == NULL){
//             printf("Bucket %d is empty", i);
//         }else{
//             printf("Bucket %d has %d data(s): ", i, HB.dataCount);
//             Node *temp = HB.HEAD;
//             while(temp != NULL){
//                 printf("%s ", temp->data);
//                 temp = temp->next;
//             }
//         }
//         printf("\n");
//     }
// }


void view(){
    for (int i = 0; i < TABLE_SIZE; i++){
        printf("HT[%d] = ", i);
        Node *temp = hashTable[i].HEAD;
        while(temp){
            printf("%s -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL.\n");
    }
}



int main(){
    push("Hello");
    push("World");

    view();
    return 0;
}