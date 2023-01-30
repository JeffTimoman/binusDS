#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 97
#define MULTIPLIER 31

struct Node{
    int key;
    char input[100];
    Node *next;
};

struct HashTable{
    int dataCount;
    Node *HEAD, *TAIL;
}HashTable[MAX];

Node *createNode(int key, char *input){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->input, input);
    newNode->next = NULL;
    return newNode;
}

int stringToInt(char *input){
    int result = 0;
    for(int i = 0; i < strlen(input); i++){
        result = result + input[i] *MULTIPLIER;
        result %= MAX;
    }
    return result;
}

int hashFunction(char *input){
    int key = stringToInt(input);
    key =  key % MAX;
    if (key < 0) key += MAX;
    return key;    
}

void insertData(char *input){
    int key = hashFunction(input);
    Node *newNode = createNode(key, input);
    if(HashTable[key].dataCount == 0){
        HashTable[key].HEAD = HashTable[key].TAIL = newNode;
    }else{
        HashTable[key].TAIL->next = newNode;
        HashTable[key].TAIL = newNode;
    }
    HashTable[key].dataCount++;
}

void printData(){
    for(int i = 0; i < MAX; i++){
        if(HashTable[i].dataCount > 0){
            Node *temp = HashTable[i].HEAD;
            printf("Key: %d, Data: ", i);
            while(temp != NULL){
                printf("%s ", temp->input);
                temp = temp->next;
            }
            printf("--> NULL");
            printf("\n");
        }
    }
}

void findData(){
    char input[100];
    scanf("%s", input);
    int key = hashFunction(input);
    if(HashTable[key].dataCount == 0){
        printf("Not found\n");
    }else{
        Node *temp = HashTable[key].HEAD;
        while(temp != NULL){
            if(strcmp(temp->input, input) == 0){
                printf("Found\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not found\n");
    }
}

void findData(char *input){
    int key = hashFunction(input);
    if(HashTable[key].dataCount == 0){
        printf("Not found\n");
    }else{
        Node *temp = HashTable[key].HEAD;
        while(temp != NULL){
            if(strcmp(temp->input, input) == 0){
                printf("Found\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not found\n");
    }
}
int main(){
    FILE *fp = fopen("CaseShift2.csv", "r");
    char input[100];
    while(fscanf(fp, "%s", input) != EOF){
        if (input[0] == '\n' || input[0] == ' ')continue;
        // printf("%d ", hashFunction(input));
        insertData(input);
    }

    printData();
    return 0;
}