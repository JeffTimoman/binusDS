#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int id;
    char name[20];
    Node *left, *right;
    int height;
}*ROOT = NULL;

int getHeight(Node *curr){
    if (!curr) return 0;
    return curr->height;
}

int calculateBalance(Node *curr){
    if (!curr) return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Node* createNode(int id, char name[]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *insertNode(Node* curr, int id, char name[]){
    if (!curr) {
        curr = createNode(id, name);
    }else if(id < curr->id){
        curr->left = insertNode(curr->left, id, name);
    }else if(id > curr->id){
        curr->right = insertNode(curr->right, id, name);
    }

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int balance = calculateBalance(curr);

    
    return curr;
}

