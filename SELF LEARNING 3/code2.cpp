#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}


int main(){

}