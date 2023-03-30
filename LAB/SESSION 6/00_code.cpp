#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    Node *left, *right;
};

Node* ROOT = NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* curr, int data){
    if(curr == NULL){
        return createNode(data);
    }else if(data < curr->data){
        curr->left = insertNode(curr->left, data);
    }else if(data > curr->data){
        curr->right = insertNode(curr->right, data);
    }
    return curr;
}

Node* getPredecessor(Node*curr){
    curr = curr->left;
    while(curr->right){
        curr = curr->right;
    }
    return curr;
}

Node* deleteNode(Node* curr, int data){
    if (curr == NULL){
        return curr;        
    }else if(curr->data > data){
        curr->left = deleteNode(curr->left, data);
    }else if(curr->data < data){
        curr->right = deleteNode(curr->right, data);
    }else if(curr->data == data){
        if (!curr->left && !curr->right){
            free(curr);
            return NULL;
        }else if(!curr->left){
            Node* temp = curr->right;
            free(curr);
            return temp;
        }else if(!curr->right){
            Node* temp = curr->left;
            free(curr);
            return temp;
        }else {
            Node* predeCesssor = getPredecessor(curr);
            curr->data = predeCesssor->data;
            curr->left = deleteNode(curr->left, predeCesssor->data);
        }
    }

    return curr;
}

Node* search(Node* curr, int data){
    if(curr == NULL){
        return NULL;
    }
    if(curr->data == data){
        return curr;
    }
    if(curr->data > data){
        return search(curr->left, data);
    }
    return search(curr->right, data);
}

void printInorder(Node* curr){
    if(curr == NULL){
        return;
    }
    printInorder(curr->left);
    printf("%d ", curr->data);
    printInorder(curr->right);
}

int main(){
    ROOT = insertNode(ROOT, 10);
    ROOT = insertNode(ROOT, 5);
    ROOT = insertNode(ROOT, 15);
    ROOT = insertNode(ROOT, 3);
    ROOT = insertNode(ROOT, 7);

    printInorder(ROOT);

    ROOT = deleteNode(ROOT, 5);

    printf("\n");
    printInorder(ROOT);
    return 0;
}





