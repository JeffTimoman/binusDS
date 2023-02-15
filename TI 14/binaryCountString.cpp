#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int sum;
    char str[100];
    Node *left, *right;
}*ROOT = NULL;

Node* createNode(int sum, char str[]){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->sum = sum;
    strcpy(newNode->str, str);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *curr, int sum, char str[]){
    if (!ROOT){
        ROOT = createNode(sum, str);
        curr = ROOT;
    }else if(!curr){
        curr = createNode(sum, str);
    }else if(strcmp(curr->str, str) > 0){
        curr->sum += strlen(str);
        curr->left = insert(curr->left, sum, str);
    }else if(strcmp(curr->str, str) < 0){
        curr->sum += strlen(str);
        curr->right = insert(curr->right, sum, str);
    }

    return curr;
}

void printInOrder(Node *curr){
    if (curr){
        printInOrder(curr->left);
        printf("%s : %d\n", curr->str, curr->sum);
        printInOrder(curr->right);
    }
}

int main(){
    insert(ROOT, 0, "andi");
    insert(ROOT, 0, "budi");
    insert(ROOT, 0, "caca");

    printInOrder(ROOT);
    return 0;
}