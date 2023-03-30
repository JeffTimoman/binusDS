#include <stdio.h>
#include <stdlib.h>


// What is binary tree in data structure?
// Binary tree is a data structure that has a root, left child, and right child.
// The left child is smaller than the root, and the right child is bigger than the root.
// The left child and the right child are also binary tree.

struct Node{
    int value;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node* createNode(int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void push(int value){
    if (!root){
        root = createNode(value);
    } else {
        Node *curr = root;
        while (curr){
            if (value < curr->value){
                if (curr->left){
                    curr = curr->left;
                } else {
                    curr->left = createNode(value);
                    break;
                }
            } else {
                if (curr->right){
                    curr = curr->right;
                } else {
                    curr->right = createNode(value);
                    break;
                }
            }
        }
    }
}
void search(int value){
    if (!root){
        puts("Data tidak ditemukan");
    } else {
        Node *curr = root;
        while (curr){
            if (value == curr->value){
                puts("Data ditemukan");
                break;
            } else if (value < curr->value){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!curr){
            puts("Data tidak ditemukan");
        }
    }
}
void printPostOrder(Node *curr){
    if (curr){
        printPostOrder(curr->left);
        printPostOrder(curr->right);
        printf("%d ", curr->value);
    }
}
void printInOrder(Node *curr){
    if (curr){
        printInOrder(curr->left);
        printf("%d ", curr->value);
        printInOrder(curr->right);
    }
}

int main(){
    push(5);
    push(3);
    push(7);
    push(1);
    push(4);

    printInOrder(root);
    puts("");
    printPostOrder(root);
    puts("");
    search(3);
    search(6);
    return 0;
}