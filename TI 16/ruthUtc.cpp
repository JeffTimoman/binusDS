#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node2{
    char membershipName[100];
    Node2 *left, *right;
}*ROOT2 = NULL;

struct Node{
    char customerName[100];
    char memberShipName[100];
    Node *left, *right;
}*ROOT = NULL;

Node* createNode(char customerName[], char memberShipName[]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->customerName, customerName);
    strcpy(newNode->memberShipName, memberShipName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node2* createNode2(char membershipName[]){
    Node2 *newNode = (Node2*)malloc(sizeof(Node2));
    strcpy(newNode->membershipName, membershipName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* curr, char customerName[], char memberShipName[]){
    if (!ROOT){
        ROOT = createNode(customerName, memberShipName);
        return ROOT;
    }else if(!curr){
        curr = createNode(customerName, memberShipName);
        return curr;
    }else if(strcmp(customerName, curr->customerName) < 0){
        curr->left = insertNode(curr->left, customerName, memberShipName);
    }else if(strcmp(customerName, curr->customerName) > 0){
        curr->right = insertNode(curr->right, customerName, memberShipName);
    }

    return curr;
}

Node2* insertNode2(Node2* curr, char membershipName[]){
    if (!ROOT2){
        ROOT2 = createNode2(membershipName);
        return ROOT2;
    }else if(!curr){
        curr = createNode2(membershipName);
        return curr;
    }else if(strcmp(membershipName, curr->membershipName) < 0){
        curr->left = insertNode2(curr->left, membershipName);
    }else if(strcmp(membershipName, curr->membershipName) > 0){
        curr->right = insertNode2(curr->right, membershipName);
    }

    return curr;
}

Node2* search2(Node2* curr, char membershipName[]){
    if (!curr){
        return NULL;
    }else if(strcmp(membershipName, curr->membershipName) == 0){
        return curr;
    }else if(strcmp(membershipName, curr->membershipName) < 0){
        return search2(curr->left, membershipName);
    }else if(strcmp(membershipName, curr->membershipName) > 0){
        return search2(curr->right, membershipName);
    }
}

void innit(){
    insertNode2(ROOT2, "Non-Member");
    insertNode2(ROOT2, "Bronze");
    insertNode2(ROOT2, "Silver");
    insertNode2(ROOT2, "Gold");
    insertNode2(ROOT2, "Platinum");
}

void addCustomer(){
    char customerName[100], memberShipName[100];
    do{
        printf("Customer Name: ");
    }while();
}

int main(){
    innit();
    int menu;
    do{
        puts("1. Add New Customer");
        puts("2. View All Customer");
        puts("3. Delete Customer");
        puts("4. Exit");
        printf(">> ");
        scanf("%d", &menu); getchar();
        switch(menu){
            case 1: 
                break;
            case 2: 
                break;
            case 3: 
                break;
            case 4: 
                break;
            default: 
                puts("Invalid Input");
                break;
        }
    }while(menu != 4);
    return 0;
}