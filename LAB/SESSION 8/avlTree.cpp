#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    Node *left, *right;
    int height;
};

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int max(int a, int b){
    return a > b ? a : b;
}
int getHeight(Node* node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalance(Node* node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* node){
    Node* pivot = node->left;
    Node* cut = pivot->right;

    pivot->right = node;
    node->left = cut;

    return pivot;
}

Node* leftRotate(Node* node){
    Node* pivot = node->right;
    Node* cut = pivot->left;

    pivot->left = node;
    node->right = cut;

    return pivot;
}

Node* insert(Node* curr, int value){
    if(curr == NULL){
        return createNode(value);
    }else if(value == curr->value){
        printf("Value already exists");
    }else if(value < curr->value){
        curr->left = insert(curr->left, value);
    }else if(value > curr->value){
        curr->right = insert(curr->right, value);
    }

    int balance = getBalance(curr);
    int height = max(getHeight(curr->left), getHeight(curr->right)) + 1;

    if(balance > 1 && value < curr->left->value){
        return rightRotate(curr);
    }

    if(balance > 1 && value > curr->left->value){
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }

    if(balance < -1 && value > curr->right->value){
        return leftRotate(curr);
    }

    if(balance < -1 && value < curr->right->value){
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}

int main(){
    return 0;
}