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
    if(!ROOT){
        ROOT = createNode(value);
    }else{
        Node* temp = createNode(value);
        Node* parent = ROOT;
        while(parent){
            if (value < parent->value){
                if (!parent->left){
                    parent->left = temp;
                    break;
                }else{
                    parent = parent->left;
                }
            }else{
                if (!parent->right){
                    parent->right = temp;
                    break;
                }else{
                    parent = parent->right;
                }
            }
        }
    }
}

void remove(int value){
    Node* parent = NULL;
    Node* target = ROOT;

    // Data yang mau di delete ada atau tidak.
    while (target){
        if (value == target->value){
            break;
        }else if(value > target->value){
            parent = target;
            target = target->right;
        }else {
            parent = target;
            target = target->left;
        }
    }

    if (!target){
        puts("Data not found ehe!");
        return;
    }

    //Case One : Target doesn't have any child
    if (!target->left && !target->right){
        if (!parent){
            ROOT = NULL;
            // free(target);
        }else{
            if (value < parent->value){
                parent->left = NULL;
                // free(target);
            }else{
                parent->right = NULL;
                // free(target);
            }
        }
        free(target);
        return;
    }

    // Case Two : Target have one child
    if(!target->left || !target->right){
        Node* child = target->left ? target->left : target->right;
        // Explaination
        // if (target->left == NULL){
        //     child = target->right;
        // }else{
        //     child = target->left;
        // }
        if(!parent){
            // free(target);
            ROOT = child;
            return;
        }else{
            if (parent->left == target){
                // free(target);
                parent->left = child;
            }else{
                // free(target);
                parent->right = child;
            }
        }
        free(target);
        return;
    }

    // Case Three : Have 2 child 
    Node* successor = target->right;
    Node* successor_parent = target;

    while(successor->left){
        successor_parent = successor;
        successor = successor->left;
    }


    if (successor_parent->left == successor){
        successor_parent->left = successor->right;
    }else{
        successor_parent->right = successor->right;
    }

    target->value = successor->value;
    free(successor);
}

void printInOrder(Node* curr){
    if (curr){
        printInOrder(curr->left);
        printf("%d ", curr->value);
        printInOrder(curr->right);
    }
}

void binarySearch(Node* curr, int value){
    if (curr->value == value){
        puts("Value finded");
    }else if(curr->value == value){
        
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
    remove(70);
    printInOrder(ROOT);
    return 0;
}