#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node{
    Node *prev;
    char type[100];
    // If hunting : fur and meat
    // If gathering : firewood and herb
    int product1;
    int product2;
    Node *next;
}*HEAD = NULL, *TAIL = NULL;

// Function prototypes
Node* createNode(char type[], int product1, int product2){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    strcpy(new_node->type, type);
    new_node->product1 = product1;
    new_node->product2 = product2;
    return new_node;
}

void pushTail(char type[], int product1, int product2){
    Node *temp = createNode(type, product1, product2);
    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->prev = TAIL;
        TAIL->next = temp;
        TAIL = temp;
    }
}

void printMenu(){
    puts("Exploration Game");
    puts("======================");
    puts("1. Explore the woods!");
    puts("2. Exploration Records");
    puts("3. Clear Exploration Records");
    puts("4. Exit");
    printf("Choice : ");
}

void printTailDetail(){
    char explorationType[100];
    int product1, product2;
    strcpy(explorationType, TAIL->type);
    product1 = TAIL->product1;
    product2 = TAIL->product2;

    puts("You explored the darkside of the woods!");
    puts("You obtained!");
    if(strcmp(explorationType, "hunting") == 0){
        printf("\t%d piece(s) of fur\n\t%d slice(s) of meat.\n", product1, product2);
    }else{
        printf("\t%d piece(s) of firewood\n\t%d pouch(s) of herb.\n", product1, product2);
    }

}
int validationExplorationType(char explorationType[]){
    if(strcmp(explorationType, "hunting") == 0 || strcmp(explorationType, "gathering") == 0){
        return 1;
    }
    
    return 0;
}

// Switch case menu
void exploreWoods(){
    char explorationType[100];
    do{
        printf("Choose exploration type [hunting|gathering] : ");
        scanf("%[^\n]", explorationType); getchar();

    }while(!validationExplorationType(explorationType));


    int time;
    do{
        printf("How long do you want to do %s? [1 - 3 hours]:  ", explorationType);
        scanf("%d", &time); getchar();
    }while(time < 1 || time > 3);

    int product1, product2;
    if (strcmp(explorationType, "hunting") == 0){
        product1 = rand() % 10 * time;
        product2 = rand() % 5 * time;
    }else{
        product1 = rand() % 100 * time;
        product2 = rand() % 5 * time;
    }

    pushTail(explorationType, product1, product2);
    printTailDetail();
}

void printRecord(){
    Node *curr = HEAD;
    int i = 1;
    puts("Exploration Records: \n");
    while(curr){
        printf("Exploration number %03d\n", i++);
        if (strcmp(curr->type, "hunting") == 0){
            printf("You go hunting and got : %d piece(s) of fur%d slice(s) of meat.\n", curr->product1, curr->product2);
        }else{
            printf("You go gathering and got : %d piece(s) of firewood %d pouch(s) of herb.\n", curr->product1, curr->product2);
        }
        puts("");
        curr = curr->next;
    }
}

void clearRecord(){
    Node *curr = HEAD;
    while(curr){
        Node *temp = curr->next;
        free(curr);
        curr = temp;
    }
    HEAD = TAIL = NULL;
}

int main(){
    srand(time(NULL));
    int menu;
    do{
        system("cls");
        printMenu();
        scanf("%d", &menu); getchar();
        switch(menu){
            case 1:
                puts("You are exploring the woods!");
                exploreWoods();
                break;
            case 2:
                puts("You are viewing your exploration records!");
                printRecord();
                break;
            case 3:
                puts("You are clearing your exploration records!");
                clearRecord();
                break;
            case 4:
                puts("You are exiting the game!");
                break;
            default:
                puts("Invalid choice!");
        }
        printf("\nPress enter to continue..."); getchar();
    }while(menu != 4);
    return 0;
}