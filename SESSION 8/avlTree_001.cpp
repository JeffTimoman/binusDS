#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value; 
    int height; 
    Node *left;
    Node *right;
};

Node *ROOT = NULL;

Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getMax(int heightLeft, int heightRight){
    return heightLeft > heightRight ? heightLeft : heightRight;
}

int getHeight(Node *node){
    if(!node) return 0;
    return node->height;
}

int calculateHeight(Node *node){
    if(!node) return 0;
    return getMax(getHeight(node->left), getHeight(node->right)) + 1;
}

int calculateBalanceFactor(Node *node){
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insert(Node *node, int value){
    if (!node){
        return createNode(value);
    }else if(value == node->value){
        printf("Duplicate value");
        return node;
    }

    node->height = calculateHeight(node);
    int balance = calculateBalanceFactor(node);

    //LL
    if (balance > 1 && value < node->left->value){

    }

    //RR
    if (balance < -1 && value > node->right->value){

    }
    //LR
    if (balance > 1 && value > node->left->value){

    }
    //RL
    if (balance < -1 && value < node->right->value){

    }
}

int main(){
    return 0;
}