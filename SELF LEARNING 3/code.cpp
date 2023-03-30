#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int patientCount = 0;
struct Quasar{
    char patienName[25];
    int priorityLevel;
    int age;
    struct Quasar *next, *prev;
}*HEAD = NULL, *TAIL = NULL;

Quasar* createNode(char name[], int priority, int age){
    Quasar *newNode = (Quasar*)malloc(sizeof(Quasar));
    strcpy(newNode->patienName, name);
    newNode->priorityLevel = priority;
    newNode->age = age;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

bool validateName(char name[]){
    if (strlen(name) < 1 || strlen(name) > 25){
        return false;
    }

    return true;
}

bool validateAge(int age){
    if (age < 1 || age > 110){
        return false;
    }

    return true;
}

bool validatePriority(int priority){
    if (priority < 1 || priority > 5){
        return false;
    }

    return true;
}


void printMenu(){
    printf("Patient: %d people(s)\n", patientCount);
    printf("Quesar Queue 1.3\n");
    printf("1. Add Patient\n");
    printf("2. Call Patient\n");
    printf("3. Remove All Patient\n");
    printf("4. Exit\n");
    printf("Select [1-4]: ");
}

void pushHead(char name[], int priority, int age){
    Quasar *temp = createNode(name, priority, age);
    if(!HEAD){
        HEAD = TAIL = temp;
    } else {
        temp->next = HEAD;
        HEAD->prev = temp;
        HEAD = temp;
    }
    patientCount++;
}

void pushTail(char name[], int priority, int age){
    Quasar *temp = createNode(name, priority, age);
    if(!HEAD){
        HEAD = TAIL = temp;
    } else {
        temp->prev = TAIL;
        TAIL->next = temp;
        TAIL = temp;
    }
    patientCount++;
}

void pushPriority(char name[], int priority, int age){
    Quasar *temp = createNode(name, priority, age);
    if(!HEAD){
        HEAD = TAIL = temp;
    } else if(HEAD->priorityLevel > priority){
        pushHead(name, priority, age);
    } else if(TAIL->priorityLevel < priority){
        pushTail(name, priority, age);
    } else {
        Quasar *curr = HEAD;
        while(curr && curr->priorityLevel < priority){
            curr = curr->next;
        }
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
    }
    patientCount++;
}

void popStack(){
    if(!HEAD){
        return;
    } else if(HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    } else {
        Quasar *temp = TAIL->prev;
        temp->next = NULL;
        free(TAIL);
        TAIL = temp;
    }
    patientCount--;
}

void popHead(){
    if(!HEAD){
        return;
    } else if(HEAD == TAIL){
        free(HEAD);
        HEAD = TAIL = NULL;
    } else {
        Quasar *temp = HEAD->next;
        temp->prev = NULL;
        free(HEAD);
        HEAD = temp;
    }
    patientCount--;
}

void addPatient(){
    char name[25];
    int priority, age;
    do {
        printf("Patient Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(!validateName(name));

    do {
        printf("Priority Level [1-5]: ");
        scanf("%d", &priority);
        getchar();
    } while(!validatePriority(priority));

    do {
        printf("Age: ");
        scanf("%d", &age);
        getchar();
    } while(!validateAge(age));

    pushPriority(name, priority, age);
}

void callPatient(){
    if(!HEAD){
        printf("No Patient!\n");
    } else {
        printf("Calling Patient: %s\n", HEAD->patienName);
        popHead();
    }
    getchar();
}

void removeAllPatient(){
    if(!HEAD){
        printf("No Patient!\n");
    } else {
        while(HEAD){
            popStack();
        }
        printf("All Patient Removed!\n");
    }
    getchar();
}


int main(){
    int menu;
    do {
        system("cls");
        printMenu();
        scanf("%d", &menu);
        getchar();
        switch(menu){
            case 1:
                printf("Add Patient\n");
                addPatient();
                break;
            case 2:
                printf("Call Patient\n");
                callPatient();
                break;
            case 3:
                printf("Remove All Patient\n");
                removeAllPatient();
                break;
            case 4:

            default:
                printf("Invalid Input!\n");
        }
    }while(menu != 4);
    return 0;
}