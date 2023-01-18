#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//3, 4, 6, 8, 9
// AVL Tree 
struct Node{
    int value;
    Node *left;
    Node *right;
    int height;
};

Node *root = NULL;

Node *createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int getHeight(Node *node){
    if (!node){
        return 0;
    }
    return node->height;
}

int getBalance(Node *node){
    if (!node){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *node){
    Node *new_root = node->left;
    Node *temp = new_root->right;

    new_root->right = node;
    node->left = temp;

    node->height = 1 + fmax(getHeight(node->left), getHeight(node->right));
    new_root->height = 1 + fmax(getHeight(new_root->left), getHeight(new_root->right));

    return new_root;
}

Node *leftRotate(Node *node){
    Node *new_root = node->right;
    Node *temp = new_root->left;

    new_root->left = node;
    node->right = temp;

    node->height = 1 + fmax(getHeight(node->left), getHeight(node->right));
    new_root->height = 1 + fmax(getHeight(new_root->left), getHeight(new_root->right));

    return new_root;
}

Node *insert(Node *node, int value){
    if (!node){
        return createNode(value);
    }

    if (value < node->value){
        node->left = insert(node->left, value);
    }else if (value > node->value){
        node->right = insert(node->right, value);
    }else{
        return node;
    }

    node->height = 1 + fmax(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value){
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && value > node->right->value){
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && value > node->left->value){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *node){
    if (node){
        printf("%d ", node->value);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node *node){
    if (node){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->value);
    }
}

void inOrder(Node *node){
    if (node){
        inOrder(node->left);
        printf("%d ", node->value);
        inOrder(node->right);
    }
}

int main(){
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    // preOrder(root);
    printf("");
    inOrder(root);
}