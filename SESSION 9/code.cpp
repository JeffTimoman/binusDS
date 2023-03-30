#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    int height;
    Node *left, *right;
};


Node* createNode(int value){
    Node* node = new Node;
    node->value = value;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// Get the height of a node
int get_height(Node* node){
    if(!node){
        return 0;
    }
    return node->height;
}

// Get the maximum of two numbers
int max(int a, int b){
    return a > b ? a : b;
}

//Calculate height of a node
int calculate_height(Node* node){
    if(!node){
        return 0;
    }
    return 1 + max(get_height(node->left), get_height(node->right));
}

int calculate_balance(Node* node){
    if(!node){
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
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

Node* right_rotate(Node* node){
    Node* pivot = node->left;
    Node* cut = pivot->right;

    pivot->right = node;
    node->left = cut;

    node->height = calculate_height(node);
    pivot->height = calculate_height(pivot);

    return pivot;
}

Node* insert(Node* node, int value){
    if(!node){
        return createNode(value);
    }else if(value == node->value){
        printf("Value already exists in the tree");
    }else if(value < node->value){
        node->left = insert(node->left, value);
    }else if(value > node->value){
        node->right = insert(node->right, value);
    }

    node->height = calculate_height(node);

    int balance = calculate_balance(node);

    // Left Left Case, balance > 1, check if have 
    if(balance > 1 && value < node->left->value){
        node = right_rotate(node);
    }

    // Left right case, balance > 1
    if(balance > 1 && value > node->left->value){
        node->left = left_rotate(node->left);
        node = right_rotate(node);
    }

    // Right right case, balance < -1
    if(balance < -1 && value > node->right->value){
        node = left_rotate(node);
    }

    // Right left case, balance < -1
    if(balance < -1 && value < node->right->value){
        node->right = right_rotate(node->right);
        node = left_rotate(node);
    }
    return node;
}

Node* del(Node*node, int value){
    if (!node){
        printf("Value not found in the tree");
    }else if(value < node->value){
        node->left = del(node->left, value);
    }else if(value > node->value){
        node->right = del(node->right, value);
    }else if(value == node->value){
        if(!node->left && !node->right){
            free(node);
            node = NULL;
        }else if(!node->left){
            Node* temp = node->right;
            free(node);
            node = temp;
        }else if(!node->right){
            Node* temp = node->left;
            free(node);
            node = temp;
        }else{
            Node* temp = node->right;
            while(temp->left){
                temp = temp->left;
            }
            node->value = temp->value;
            node->right = del(node->right, temp->value);
        }
    }

    if(!node){
        return node;
    }

    node->height = calculate_height(node);
    int balance = calculate_balance(node);
    
    // LL case, balance > 1, check if the value is in the left subtree or right subtree
    if(balance > 1 && calculate_balance(node->left) >= 0){
        node = right_rotate(node);

    // LR case, balance > 1, check if the value is in the left subtree or right subtree
    }else if(balance > 1 && calculate_balance(node->left) < 0){
        node->left = left_rotate(node->left);
        node = right_rotate(node);
    
    //RR case, balance < -1, check if the value is in the left subtree or right subtree
    }else if(balance < -1 && calculate_balance(node->right) <= 0){
        node = left_rotate(node);
    //RL case, balance < -1, check if the value is in the left subtree or right subtree
    }else if(balance < -1 && calculate_balance(node->right) > 0){
        node->right = right_rotate(node->right);
        node = left_rotate(node);
    }

    return node;
}

int main(){
    return 0;
}