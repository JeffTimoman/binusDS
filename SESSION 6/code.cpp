#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *left, *right;
};

Node *ROOT = NULL;

Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void pre_order(Node *curr){
    if (curr != NULL){
        printf("%d ", curr->value);
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

Node* insert_node(Node *curr, int value){
    //Pake ini ga perlu pake ROOT =
    // if (!ROOT){
    //     return ROOT = createNode(value);
    // }
    if (!curr){
        return createNode(value);
    }

    if (curr->value > value){
        curr->left = insert_node(curr->left, value);
    }else if (curr->value < value){
        curr->right = insert_node(curr->right, value);
    }

    return curr;
}

Node* getPredecessor(Node *curr){
    curr = curr->left;
    while(curr->right){
        curr = curr->right;
    }
    return curr;
}

Node* delete_node(Node *curr, int value){
    if (!curr){
        printf("Data not found\n");
        return NULL;
    }
    else if(curr->value > value){
        curr->left = delete_node(curr->left, value);
    }
    else if(curr->value < value){
        curr->right = delete_node(curr->right, value);
    }
    else if(value == curr->value){
        if (!curr->left && !curr->right){
            free(curr);
            return NULL;
        }
        else if(!curr->left){
            Node *temp = curr->right;
            free(curr);
            return temp;
        }
        else if(!curr->right){
            Node *temp = curr->left;
            free(curr);
            return temp;
        }
        else{
            Node *temp = getPredecessor(curr);
            curr->value = temp->value;
            curr->left = delete_node(curr->left, temp->value);
        }
    }
    return curr;
}


// Node* delete_node(Node *curr, int value){
//     if (!curr){
//         printf("Data not found");
//         return NULL;
//     }else if(curr->value > value){
//         curr->left = delete_node(curr->left, value);
//     } else if(curr->value < value){
        
//     }else if(value == curr->value){
//         if (!curr->left && !curr->value){
//             free(curr);
//             return NULL;
//         }else if(!curr->left){
//             Node *temp = curr->right;
//             free(curr);
//             // curr = temp;
//             return temp;
//         }else if(!curr->right){
//             Node *temp = curr->left;
//             free(curr);
//             // curr = temp;
//             return temp;
//         }else{
//             Node *temp = getPredecessor(curr);
//             curr->value = temp->value;
//             curr->left = delete_node(curr->left, temp->value);
//         }
//     }

//     return curr;
// }

Node* popAll(Node *curr){
    if (curr != NULL){
        popAll(curr->left);
        popAll(curr->right);
        free(curr);
        curr = NULL;
    }
    return NULL;
}

void popAll2(){
    while(ROOT){
        ROOT = delete_node(ROOT, ROOT->value);
    }
}

int getAllTreeValue(Node*curr){
    if (curr != NULL){
        return curr->value + getAllTreeValue(curr->left) + getAllTreeValue(curr->right);
    }
    return 0;
}

int sum = 0;
void getAllTreeValue2(Node *curr){
    if (curr != NULL){
        getAllTreeValue2(curr->left);
        sum += curr->value;
        getAllTreeValue2(curr->right);
    }
}


int main(){
    ROOT = insert_node(ROOT, 10);
    ROOT = insert_node(ROOT, 5);
    ROOT = insert_node(ROOT, 2);
    ROOT = insert_node(ROOT, 7);
    ROOT = insert_node(ROOT, 20);

    pre_order(ROOT);
    puts("");
    ROOT = delete_node(ROOT, 10);
    ROOT = delete_node(ROOT, 13);


    pre_order(ROOT);
    puts("");
    printf("%d", getAllTreeValue(ROOT));
    return 0;
}
