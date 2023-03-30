#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 11
#define BASE_NUMBER 7

struct Node{
    int key; 
    char value[1000];
    Node *next;
};

struct HashTable{
    int dataCount;
    Node *HEAD, *TAIL;
}hashTable[TABLE_SIZE];

int StringToInt(char value[]){
    int result = 0;
    // Give a good algorithm to convert string to integer
    for (int i = 0; i < strlen(value); i++){
        result += value[i] + value[strlen(value) - i - 1] * BASE_NUMBER;
        result %= TABLE_SIZE;
    }
    return result;
}

int hashFunction(char value[]){
    return StringToInt(value) % TABLE_SIZE;
}

Node* createNode(char value[]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = hashFunction(value);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

void pushData(Node *newNode){
    int key = newNode->key;
    if (hashTable[key].dataCount == 0){
        hashTable[key].HEAD = hashTable[key].TAIL = newNode;
    }else{
        hashTable[key].TAIL->next = newNode;
        hashTable[key].TAIL = newNode;
    }
    hashTable[key].dataCount++;
}

void searchData(int key, char value[]){
    if (hashTable[key].dataCount == 0){
        printf("Data Not Found\n");
    } else{
        int count = 1;
        Node *curr = hashTable[key].HEAD;
        while(curr){
            if (strcmp(curr->value, value) == 0){
                printf("%s found at table[%d], index[%d].\n", value, key, count);
                return;
            }
            count++;
        }

        printf("Data Not Found\n");
    }
}

int validateString(char value[]){
    if(value[0] == '\n') return 0;
    
    if (strlen(value) > 1000 || strlen(value) < 1){
        return 0;
    }

    return 1;
}

void printMenu(){
    printf("Menu Hashing\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Exit\n");
    printf(">> ");
}

void printAll(){
    for (int i = 0; i < TABLE_SIZE; i++){
        printf("Table[%d] : ", i);
        Node *curr = hashTable[i].HEAD;
        while(curr){
            printf("%s -> ", curr->value);
            curr = curr->next;
        }
        printf("NULL");
        puts("");
    }
}
void insertData(){
    char value[1000];
    do{
        printf("Input String [1-1000]: "); 
        scanf("%[^\n]", value);
        fflush(stdin);
    }while(!validateString(value));

    Node *newNode = createNode(value);
    pushData(newNode);
    printf("%s inserted in table %d\n", value, newNode->key);
}
void searchData(){
    char value[1000];
    do{
        printf("Input String [1-1000]: "); 
        scanf("%[^\n]", value); fflush(stdin);
        if (value[0] == '\n') continue;
    }while(!validateString(value));
    searchData(hashFunction(value), value);
}

void pressAnyKey(){
    printf("Press any key to continue...");
    getchar();
    fflush(stdin);
}
int main(){
    int menu;
    do{
        system("cls");
        printAll();
        printMenu();
        scanf("%d", &menu); fflush(stdin);

        switch(menu){
            case 1 :
                puts("Insert Data");
                insertData();
                pressAnyKey();
                break; 
            case 2 : 
                puts("Search Data");
                searchData();
                pressAnyKey();
                break;
            case 3 :
                puts("Exit");
                break;
            default : 
                puts("Invalid Input!");
                break;
        }
    }while(menu != 3);
    return 0;
}