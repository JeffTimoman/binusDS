#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int patientCount = 0;

struct Quasar {
    char patient_name[25];
    int priorityLevel;
    int age;
    struct Quasar *next, *prev;
} *HEAD, *TAIL;

Quasar* createNode(char name[], int priority, int age){
    Quasar *temp = (Quasar*) malloc(sizeof(Quasar));
    strcpy(temp->patient_name, name);
    temp->priorityLevel = priority;
    temp->age = age;
    temp->next = temp->prev = NULL;
    return temp;
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

void addPatient(){
    char name[25];
    int priority, age;
    do{
        printf("Input Patient Name[1..25] :  ");
        scanf("%[^\n]", name);
        getchar();
    }while(!validateName(name));

    do{
        puts("1. Emergency");
        puts("2. Super VIP");
        puts("3. VIP");
        puts("4. Basic");
        printf("Select [1..4]: ");
        scanf("%d", &priority);
        getchar();
    }while(!validatePriority(priority));

    do{
        printf("Input Age: ");
        scanf("%d", &age);
        getchar();
    }while(!validateAge(age));

    pushPriority(name, priority, age);

}

void viewPatient(){
    puts("Quasar Hospital Queue");
    puts("-------------------------------");
    int count = 1;
    Quasar *curr = HEAD;
    while(curr){
        if (curr->priorityLevel == 1){
            printf("%2d. %-10s : %-20s \n", count, "(Emergency)", curr->patient_name);
        } else if (curr->priorityLevel == 2){
            printf("%2d. %-10s : %-20s \n", count, "(Super VIP)", curr->patient_name);
        } else if (curr->priorityLevel == 3){
            printf("%2d. %-10s : %-20s \n", count, "(VIP)", curr->patient_name);
        } else if (curr->priorityLevel == 4){
            printf("%2d. %-10s : %-20s \n", count, "(Basic)", curr->patient_name);
        }
        curr = curr->next;
    }
}

void callPatient(){
    if(!HEAD){
        puts("No patient to be called...");
    } else {
        Quasar *temp = HEAD;
        if(HEAD == TAIL){
            HEAD = TAIL = NULL;
        } else {
            HEAD = HEAD->next;
            HEAD->prev = NULL;
        }
        puts("Attention Please!!");
        if (temp->priorityLevel == 1){
            puts("Patient from Emergency room.");
        }else if(temp->priorityLevel == 2){
            puts("Patient from Super VIP room.");
        }else if(temp->priorityLevel == 3){
            puts("Patient from VIP room.");
        }else if(temp->priorityLevel == 4){
            puts("Patient from Basic room.");
        }

        printf("With name %s, %d years", temp->patient_name, temp->age);
        puts("Please moving ahead to Administration Room.");
        free(temp);
        patientCount--;
    }
}

void removeAllPatient(){
    if(!HEAD){
        puts("No patient to be removed...");
    } else {
        Quasar *curr = HEAD, *temp;
        while(curr){
            temp = curr;
            curr = curr->next;
            free(temp);
        }
        HEAD = TAIL = NULL;
        patientCount = 0;
        puts("All patient list has been purged.");
    }
}
void printMenu(){

    if(patientCount > 0) {
        viewPatient();
    } 
    puts("");
    printf("Patient: %d people(s)\n", patientCount);
    printf("Quesar Queue 1.3\n");
    printf("=======================\n");
    printf("1. Add Patient\n");
    printf("2. Call Patient\n");
    printf("3. Remove All Patient\n");
    printf("4. Exit\n");
    printf("Select [1-4]: ");
}


int main(){
    int menu;
    do{
        system("cls");
        printMenu();
        scanf("%d", &menu);
        getchar();

        switch(menu){
            case 1:
                addPatient();
                break;
            case 2:
                callPatient();
                break;
            case 3:
                removeAllPatient();
                break;
            case 4:
                puts("Thank you for using Quasar Queue 1.3");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
        printf("Press enter to continue...");
        getchar();
    }while(menu != 4);
    return 0;
}