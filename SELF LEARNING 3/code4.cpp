#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int patientCount = 0;

struct Patient {
    char name[25];
    int priority;
    int age;
    struct Patient *next, *prev;
} *head, *tail;

// Create a new patient node and return its pointer
Patient* createPatientNode(char name[], int priority, int age) {
    Patient *node = (Patient*) malloc(sizeof(Patient));
    strcpy(node->name, name);
    node->priority = priority;
    node->age = age;
    node->next = node->prev = NULL;
    return node;
}

// Insert a patient node at the head of the linked list
void insertPatientAtHead(Patient *node) {
    if (!head) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    patientCount++;
}

// Insert a patient node at the tail of the linked list
void insertPatientAtTail(Patient *node) {
    if (!head) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    patientCount++;
}

// Insert a patient node at the correct position based on its priority
void insertPatientByPriority(Patient *node) {
    if (!head) {
        head = tail = node;
    } else if (head->priority > node->priority) {
        insertPatientAtHead(node);
    } else if (tail->priority < node->priority) {
        insertPatientAtTail(node);
    } else {
        Patient *curr = head;
        while (curr && curr->priority < node->priority) {
            curr = curr->next;
        }
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
}

// Get the patient name from user input and validate it
char* getPatientName() {
    char name[25];
    do {
        printf("Input Patient Name[1..25] :  ");
        scanf("%[^\n]", name);
        getchar();
    } while (strlen(name) < 1 || strlen(name) > 25);
    
        return name;
}

// Get the patient priority from user input and validate it
int getPatientPriority() {
    int priority;
    do {
        puts("1. Emergency");
        puts("2. Super VIP");
        puts("3. VIP");
        puts("4. Basic");
        printf("Select [1..4]: ");
        scanf("%d", &priority);
        getchar();
    } while (priority < 1 || priority > 4);
    return priority;
}

// Get the patient age from user input and validate it
int getPatientAge() {
    int age;
    do {
        printf("Input Age: ");
        scanf("%d", &age);
        getchar();
    } while (age < 1 || age > 110);
    return age;
}

// Add a new patient to the linked list
void addPatient() {
    char *name = getPatientName();
    int priority = getPatientPriority();
    int age = getPatientAge();
    Patient *node = createPatientNode(name, priority, age);
    insertPatientByPriority(node);
}

// View all patients in the linked list
void viewPatients() {
    puts("Quasar Hospital Queue");
    puts("-------------------------------");
    int count = 1;
    Patient *curr = head;
    while (curr) {
        char *priority;
        switch (curr->priority) {
            case 1: priority = "Emergency"; break;
            case 2: priority = "Super VIP"; break;
            case 3: priority = "VIP"; break;
            case 4: priority = "Basic"; break;
        }
        printf("%2d. %-10s : %-20s \n", count, priority, curr->name);
        curr = curr->next;
        count++;
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
