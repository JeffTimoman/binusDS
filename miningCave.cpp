#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int index;
    int production;
    int depth;
    Node *left;
    Node *right;
}*ROOT = NULL;


Node* createNode(int index, int production, int depth){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->index = index;
    newNode->production = production;
    newNode->depth = depth;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* curr, int index, int production, int depth){
    if(!ROOT){
        ROOT = createNode(index, production, depth);
        curr = ROOT;
        printf("\nNew cave index detected.\n");
        printf("Total gold production for Cave %d is %d.\n\n", index, production);
    }else if (!curr){
        curr = createNode(index, production, depth);
        printf("\nNew cave index detected.\n");
        printf("Total gold production for Cave %d is %d.\n\n", index, production);
    }else if (curr->index == index){
        curr->production += production;
        printf("\nCave index already exists");
        printf("New total gold production for Cave %d is %d.\n\n", index, production);
    }else if(index > curr->index){
        curr->right = insert(curr->right, index, production, depth + 1);
    }else if(index < curr->index){
        curr->left = insert(curr->left, index, production, depth + 1);
    }

    return curr;
}

void insertMiningData(){
    int index;
    do{
        printf("Input cave index [1-999]    : ");
        scanf("%d", &index); getchar();
    }while(index < 1 || index > 999);
    
    int production;
    do{
        printf("Input gold production [1-100]: ");
        scanf("%d", &production); getchar();
    }while(production < 1 || production > 100);

    insert(ROOT, index, production, 1);
}

void printInOrder(Node *curr){
    if (ROOT == NULL){
        printf("Cave data is empty, nothing to display.\n\n");
        return;
    }
    if (curr){
        printInOrder(curr->left);
        printf(">> Cave %d   (depth %d  ), total gold production : %d\n", curr->index, curr->depth, curr->production);
        printInOrder(curr->right);
    }
}

void countProduction(Node *curr, int counter[]){
    if(curr){
        counter[curr->depth] += curr->production;
        countProduction(curr->left, counter);
        countProduction(curr->right, counter);
    }
}

void printReports(){
    int counter[1005] = {};
    countProduction(ROOT, counter);
    for (int i = 1; i < 1000; i++){
        if (counter[i] != 0){
            printf(">> Total gold production for depth %d is %d\n", i, counter[i]);
        }
    }
    puts("");
}

int main(){
    insert(ROOT, 52, 10, 1);
    insert(ROOT, 31, 15, 1);
    insert(ROOT, 27, 25, 1);
    insert(ROOT, 40, 11, 1);
    insert(ROOT, 79, 89, 1);
    insert(ROOT, 65, 4, 1);
    insert(ROOT, 82, 2, 1);
    insert(ROOT, 94, 51, 1);
    insert(ROOT, 40, 13, 1);

    int menu;
    do{
        system("cls");
        puts("HOV Mining Simulator");
        puts("====================");
        puts("[1] Insert Mining Data");
        puts("[2] Display All Cave Data");
        puts("[3] Display Mining Reports");
        puts("[4] Exit");
        printf(">> ");
        scanf("%d", &menu); getchar();
        switch(menu){
            case 1:
                puts("Insert Mining Data");
                insertMiningData();
                break;
            case 2: 
                puts("Display All Cave Data");
                printInOrder(ROOT);
                break;
            case 3: 
                puts("Display Mining Reports");
                printReports();
                break;
            case 4:
                puts("Exit");
                break;
            default : 
                puts("Invalid menu");
                break;
        }
        printf("Press any key to continue..."); getchar();
    }while(menu != 4);
    return 0;
}