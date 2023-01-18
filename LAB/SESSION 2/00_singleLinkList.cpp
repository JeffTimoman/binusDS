#include <stdio.h>
#include <stdlib.h>

struct Food{
    int price;
    Food *next;
};

Food *HEAD = NULL, *TAIL = NULL;

struct Food* createFood(int price){
    Food *temp = (Food*) malloc(sizeof(Food));
    temp->price = price;
    temp->next = NULL;
    return temp;
}


int main(){
    return 0;
}