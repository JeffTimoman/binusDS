#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char name[100];
    int level;
    Node *next, *prev;
}*HEAD = NULL, *TAIL = NULL;

Node* createNode(char name[], int level){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->level = level;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(char name[], int level){
    if(!HEAD){
        HEAD = TAIL = createNode(name, level);
    }else{
        Node *curr = HEAD, *temp = createNode(name, level);
        while(level <= curr->level && curr->next != NULL){
            curr = curr->next;
        }

        if (curr == TAIL){
            curr->next = temp;
            TAIL = temp;
        }else{
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;   
        }
    }
}

int priorityToLevel(char str[]){
    if (strcmp(str, "Critical") == 0){
        return 1;
    }else if(strcmp(str, "Serious") == 0){
        return 2;
    }else if(strcmp(str, "Fair") == 0 || strcmp(str, "Good") == 0){
        return 3;
    }
}

void call(){
    if (!HEAD){
        printf("No patient\n");
    }else {
        
        if (HEAD->level == 1){
            printf("%s is in the Emergency Room\n", HEAD->name);
        }else if(HEAD->level == 2){
            printf("%s is in the Examinaion Room\n", HEAD->name);
        }else if(HEAD->level == 3){
            printf("%s is in the Consultation Room\n", HEAD->name);
        }

        if (HEAD == TAIL){
            HEAD = TAIL = NULL;
        }else{
            HEAD = HEAD->next;
            HEAD->prev = NULL;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; i++){
        char queue[100];
        scanf("%s", queue); getchar();
        if (strcmp(queue, "ADD") == 0){
            char name[100], priority[100];
            scanf("%s %s", name, priority); getchar();
            insert(name, priorityToLevel(priority));
        }else {
            call();
            getchar();
        }
    }
    printf("Waiting Room : ");
    Node* temp = HEAD;
    while(temp){
        printf("%s ", temp->name);
    }
    puts("");

    return 0;
}

