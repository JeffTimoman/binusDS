#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[100];
    int age;
    struct Node *left, *right;
}*ROOT = NULL;

Node* createNode(char name[], int age){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* curr, char name[], int age){
    if(curr == NULL){
        return createNode(name, age);
    }else if(strcmp(name, curr->name) < 0){
        curr->left = insert(curr->left, name, age);
    }else if(strcmp(name, curr->name) > 0){
        curr->right = insert(curr->right, name, age);
    }
    return curr;
}

Node* findMember(Node* curr, char name[], int lengthCount){
    if (curr == NULL){
        printf("Member not found!\n");
        return NULL;
    } else if(strcmp(name, curr->name) < 0){
        return findMember(curr->left, name, lengthCount + strlen(curr->name));
    } else if(strcmp(name, curr->name) > 0){
        return findMember(curr->right, name, lengthCount + strlen(curr->name));
    } else if(strcmp(name, curr->name) == 0){
        printf("Member found!\n");
        puts("Member Detail :");
        printf("\tName: %s\n", curr->name);
        printf("\tAge: %d\n", curr->age);
        printf("\tPath: %d\n", lengthCount);
    }
}

Node* deleteMember(Node* curr, char name[]){
    if (curr == NULL){
        printf("Member not found!\n");
        return NULL;
    } else if(strcmp(name, curr->name) < 0){
        curr->left = deleteMember(curr->left, name);
    } else if(strcmp(name, curr->name) > 0){
        curr->right = deleteMember(curr->right, name);
    } else if(strcmp(name, curr->name) == 0){
        if(curr->left == NULL && curr->right == NULL){
            free(curr);
            return NULL;
        } else if(curr->left == NULL){
            Node *temp = curr->right;
            free(curr);
            return temp;
        } else if(curr->right == NULL){
            Node *temp = curr->left;
            free(curr);
            return temp;
        } else {
            Node *temp = curr->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            strcpy(curr->name, temp->name);
            curr->age = temp->age;
            curr->right = deleteMember(curr->right, temp->name);
        }
    }
}

void addNewMember(){
    printf("Inserting new member!\n");
    char name[100];
    do{
        printf("Enter Name: ");
        scanf("%[^\n]", name); getchar();
        if(strlen(name) < 1){
            printf("Name must be filled!\n");
        }
    }while(strlen(name) < 1);

    int age;
    do{
        printf("Enter Age: ");
        scanf("%d", &age); getchar();
        if(age < 1){
            printf("Age must be greater than 0!\n");
        }
    }while(age < 1);

    ROOT = insert(ROOT, name, age);
}

void deleteAMember(){
    printf("Deleting a member!\n");
    char name[100];
    do{
        printf("Enter Name: ");
        scanf("%[^\n]", name); getchar();
        if(strlen(name) < 1){
            printf("Name must be filled!\n");
        }
    }while(strlen(name) < 1);

    ROOT = deleteMember(ROOT, name);
    printf("Member %s has been deleted!\n", name);
}

void addAge(Node* curr, int age){
    if(curr == NULL){
        return;
    }
    curr->age += age;
    addAge(curr->left, age);
    addAge(curr->right, age);
}

void addAgeToMember(){
    printf("Adding age to all member!\n");
    int age;
    do{
        printf("Enter Age: ");
        scanf("%d", &age); getchar();
        if(age < 1){
            printf("Age must be greater than 0!\n");
        }
    }while(age < 1);

    addAge(ROOT, age);
}

void findMemberEh(){
    printf("Finding member!\n");
    char name[100];
    do{
        printf("Enter Name: ");
        scanf("%[^\n]", name); getchar();
        if(strlen(name) < 1){
            printf("Name must be filled!\n");
        }
    }while(strlen(name) < 1);

    findMember(ROOT, name, 0);

}
void printMenu(){
    puts("JoLiBi Family Tree");
    puts("1. Add a new member");
    puts("2. Find member detail");
    puts("3. Delete a member");
    puts("4. Add age to all member ");
    puts("5. Exit");
    printf(">> ");
}

int main(){
    int menu;
    do{
        printMenu();
        scanf("%d", &menu); getchar();
        switch(menu){
            case 1: 
                addNewMember();
                break;
            case 2: 
                findMemberEh();
                break;
            case 3: 
                deleteAMember();
                break;

            case 4:
                addAgeToMember();
                break;
            case 5: 
                puts("Thank you for using this program!");
                break;
            default :
                puts("Tree function doesn't exist!");
                break;
        }
        printf("Press enter to continue..."); getchar();
    }while(menu != 5);
    return 0;
}