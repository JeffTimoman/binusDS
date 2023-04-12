#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value; 
    int height; 
    Node *left;Node* right;
}*ROOT = NULL;

Node* create_node(int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int get_height(Node* node){
    if(!node){
        return 0;
    }
    return node->height;
}

int max(int a, int b){
    return a > b ? a : b;
}

int calculate_height(Node* node){
    if(!node){
        return 0;
    }
    return 1 + max(get_height(node->left), get_height(node->right));
}

int calculate_balance(Node* node){
    if(!node)return 0;
    return get_height(node->left) - get_height(node->right);
}

Node* right_rotate(Node* node){
    Node* pivot = node->left;
    Node* cut = pivot->right;

    pivot->right = node;
    node->left = cut;

    node->height = calculate_height(node);
    pivot->height = calculate_height(pivot);

    return pivot;
}

Node* left_rotate(Node* node){
    Node* pivot = node->right;
    Node* cut = pivot->left;

    pivot->left = node;
    node->right = cut;

    node->height = calculate_height(node);
    pivot->height = calculate_height(pivot);
    
    return pivot;
}

Node* insert(Node* node, int value){
    if(!node){
        node = create_node(value);
    }else if(value == node->value){
        printf("Value already exists in the tree!");
    }else if(value < node->value){
        node->left = insert(node->left, value);
    }else if(value > node->value){
        node->right = insert(node->right, value);
    }

    node->height = calculate_height(node);

    int balance = calculate_balance(node);

    // LL
    if (balance > 1 && value < node->left->value){
        node = right_rotate(node);
    }

    //LR 
    if(balance > 1 && value > node->left->value){
        node->left = left_rotate(node->left);
        node = right_rotate(node);
    }

    //RR
    if (balance < -1 && value > node->right->value){
        node = left_rotate(node);
    }

    //RL
    if (balance < -1 && value < node->right->value){
        node->right = right_rotate(node->right);
        node = left_rotate(node);
    }

    return node;
}

int main(){
    return 0;
}