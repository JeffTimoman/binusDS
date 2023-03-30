#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *left;
    Node *right;
};

Node* ROOT = NULL;

Node* createNode(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}   

void push(int value){
    Node* temp = createNode(value);
    if(!ROOT){
        ROOT = temp;
    }else{
        Node* parent = ROOT;
        while (parent){
            if (value < parent->value){
                if (parent->left){
                    parent = parent->left;
                }else{
                    // IF PARENT-> left == NULL, then
                    parent->left = temp;
                    break;
                }
            }else{
                if(parent->right){
                    parent = parent -> right;
                }else{
                    parent->right = temp;
                    break;
                }
            }
        }
    }
}

void deletion(int value){

    if (!ROOT){
        puts("Tree is empty");
        return;
    }

    Node* parent = NULL;
    Node* current = ROOT;
    while(current){
        if (value == current->value){
            break;
        }else if (value < current->value){
            parent = current;
            current = current->left;
        }else{
            parent = current;
            current = current->right;
        }
    }

    // printf("Current: %d ", current->value);
    // if (parent) printf("Parent: %d", parent->value);
    // puts("");

    // If the value does not exist
    if (!current){
        puts("Value not found");
        return;
    }

    // If the value is a leaf node, and the value in the left and right is NULL
    if (!current->left && !current->right){
        if (parent){
            if (parent->left == current){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else{
            ROOT = NULL;
        }
        free(current);
        return;
    }

    // If the value has only one child
    if (!current->left || !current->right){
        Node* child = current->left ? current->left : current->right;
        if (parent){
            if (parent->left == current){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }else{
            ROOT = child;
        }
        free(current);
        return;
    }

    // If the value has two children
    Node* successor = current->right;
    Node* successor_parent = current;
    while(successor->left){
        successor_parent = successor;
        successor = successor->left;
    }

    // printf("Successor: %d ", successor->value);
    // if (successor_parent) printf("Successor Parent: %d", successor_parent->value);
    // puts("");

    if (successor_parent->left == successor){
        successor_parent->left = successor->right;
    }else{
        successor_parent->right = successor->right;
    }

    current->value = successor->value;
    free(successor);
}
void printInOrder(Node* root){
    if(root){
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}
int main(){
    push(50);
    push(25);
    push(75);
    push(6);
    push(30);
    push(60);
    push(70);
    push(52);
    printInOrder(ROOT);
    puts("");
    deletion(75);
    printInOrder(ROOT);
    return 0;
}