#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{
    int cave;
    int depth;
    int production;
    Node *left, *right;
}*ROOT = NULL;

int miningReport[1000] = {};

Node* createNode(int cave, int production, int depth){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->cave = cave;
    newNode->production = production;
    newNode->depth = depth;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertCave(Node* curr, int cave, int production, int *depth){
    if (!curr){
        printf("New cave index detected.\n");
        printf("Total gold production for Cave is %d\n", production);
        curr = createNode(cave, production, *depth);
        return curr;
    }

    if(curr->cave > cave){
        (*depth)++;
        curr->left = insertCave(curr->left, cave, production, depth);
    }else if (curr->cave < cave){
        (*depth)++;
        curr->right = insertCave(curr->right, cave, production, depth);
    }else if (curr->cave == cave){
        printf("Cave index already exists.\n");
        curr->production += production;
        printf("New total gold production is %d.\n", curr->production);
    }
    return curr;
}

void printAll(Node *curr = ROOT){
    if (curr != NULL){
        printAll(curr->left);
        printf(">> Cave %d (depth %d ), total gold production: %d\n", curr->cave, curr->depth, curr->production);
        printAll(curr->right);
    }

}

void reset(){
    memset(miningReport, 0, sizeof(miningReport));
}

void countDepth(Node *curr = ROOT){
    if (curr != NULL){
        countDepth(curr->left);
        miningReport[curr->depth] += curr->production;
        countDepth(curr->right);
    }
}

// Switch case functions
void insertMiningData(){
    int cave; 
    do{
        printf("Input cave index[1-999]      : ");
        scanf("%d", &cave); getchar();
    }while(cave < 1 || cave > 999);

    int production;

    do{
        printf("Input gold production[1-100] :");
        scanf("%d", &production); getchar();
    }while(production < 1 || production > 100);

    puts("");
    int depth = 1;
    ROOT = insertCave(ROOT, cave, production, &depth);
    free(&depth);
    puts("");
}

void printMenu(){
    puts("Hov Mining Simulator");
    puts("================================");
    puts("[1] Insert Mining Data");
    puts("[2] Display All Cave Data");
    puts("[3] Display Mining Data");
    puts("[4] Exit");
    printf(">> ");
}

void displayAllCave(){
    if (!ROOT){
        puts("Cave data is empty, nothing to display!");
        return;
    }

    printAll(ROOT);
    
}

void displayMiningReports(){
    reset();
    countDepth(ROOT);

    if (!ROOT){
        puts("Cave data is empty, nothing to display!\n");
        return;
    }

    for (int i = 0; i < 1000; i++){
        if (miningReport[i] != 0){
            printf("Total gold production for depth %d is : %d\n", i, miningReport[i]);
        }
    }
    puts("");
}

void popAll(){
    while(ROOT){
        Node *temp = ROOT;
        ROOT = ROOT->right;
        free(temp);
    }
}
void test(){
    int temp = 1;
    ROOT = insertCave(ROOT, 50, 30, &temp);
    temp = 1;
    ROOT = insertCave(ROOT, 30, 20, &temp);
    temp = 1;
    ROOT = insertCave(ROOT, 70, 40, &temp);
    temp = 1;
    ROOT = insertCave(ROOT, 20, 10, &temp);
    displayAllCave();
}

int main(){
    int menu;
    // test();
    do{
        system("cls");
        printMenu();
        scanf("%d", &menu); getchar();
        switch(menu){
            case 1:
                insertMiningData();
                break;
            case 2: 
                displayAllCave();
                break;
            case 3:
                displayMiningReports();
                break;
            case 4:
                popAll();
                puts("All data has been removed from memory!");
                puts("Thank you for playing, see you again!");
                break;
            default:
                break;
        }
        printf("Press to continue ..."); getchar();
    }while(menu != 4);
    return 0;
}