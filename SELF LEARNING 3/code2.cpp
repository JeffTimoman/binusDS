#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int patientCount = 0;
struct Quasar {
    char patient_name[25];
    int priorityLevel;
    int age;
    struct Quasar *next, *prev;
} *head, *tail;

struct Quasar* createPatient(char* name, int priority, int age) {
    struct Quasar *newPatient = (struct Quasar*)malloc(sizeof(struct Quasar));
    strcpy(newPatient->patient_name, name);
    newPatient->priorityLevel = priority;
    newPatient->age = age;
    newPatient->next = NULL;
    newPatient->prev = NULL;
    return newPatient;
}

void callPatient() {
    //check if the list is empty
    if(head == NULL) {
        printf("No patients in the queue\n");
    }
    else {
        //get the patient at the front of the list
        struct Quasar *current = head;
        printf("Patient Name: %s\n", current->patient_name);
        printf("Priority Level: %d\n", current->priorityLevel);
        printf("Age: %d\n", current->age);
        //remove the patient from the list
        head = current->next;
        free(current);
    }
}

void removeAllPatients() {
    //traverse the list and remove each node
    struct Quasar *current = head;
    while(current != NULL) {
        struct Quasar *temp = current->next;
        free(current);
        current = temp;
    }
    head = NULL;
    tail = NULL;
}

void addPatient(char* name, int priority, int age) {
    //create a new patient
    struct Quasar *newPatient = createPatient(name, priority, age);

    //check if the list is empty
    if(head == NULL) {
        head = newPatient;
        tail = newPatient;
    }
    else {
        //find the correct position for the new patient
        struct Quasar *current = head;
        while(current->next != NULL && current->priorityLevel < priority) {
            current = current->next;
        }
        //insert the new patient
        if(current->prev == NULL) {
            newPatient->next = current;
            current->prev = newPatient;
            head = newPatient;
        }
        else {
            newPatient->prev = current->prev;
            newPatient->next = current;
            current->prev->next = newPatient;
            current->prev = newPatient;
        }
    }
    patientCount++;
}

bool validateName(char* name) {
    if(strlen(name) < 1 || strlen(name) > 25) {
        printf("Name must be at least 3 characters long\n");
        return false;
    }
    return true;
}

bool validateClass(int priority) {
    if(priority < 1 || priority > 4) {
        printf("Priority level must be between 1 and 4\n");
        return false;
    }
    return true;
}

bool validateAge(int age) {
    if(age < 1 || age > 120) {
        printf("Age must be between 1 and 120\n");
        return false;
    }
    return true;
}

void case1() {
    char name[25];
    int priority, age;
    printf("Enter patient name: ");
    scanf("%s", name);
    printf("Enter patient priority level (1-4): ");
    scanf("%d", &priority);
    printf("Enter patient age: ");
    getchar();
    scanf("%d", &age);
    getchar();
    addPatient(name, priority, age);
}

int main() {
    int choice;
    char name[25];
    int priority, age;
    while(1) {
        system("cls");
        printf("Quasar Hospital Queue\n");
        printf("1. Add Patient\n");
        printf("2. Call Patient\n");
        printf("3. Remove All Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                case1();
                break;
            case 2:
                callPatient();
                break;
            case 3:
                removeAllPatients();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Press enter to continue...");
        getchar();
    }
    return 0;
}
