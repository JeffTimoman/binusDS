#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int index;
    int production;
    Node *left;
    Node *right;
}*ROOT = NULL;

Node* createNode(int index, int production){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->index = index;
    newNode->production = production;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(){
    return 0;
}