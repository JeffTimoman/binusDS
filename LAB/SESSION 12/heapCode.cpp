#include<stdio.h>
#include<string.h>
#define max 100

struct Food{
    char name[100];
    int price;
}foods[max];

int currSize = 1;

void swap(Food &a, Food &b){
    Food temp = a;
    a = b;
    b = temp;
}

void heapify(int curr , int size){
    int left = (curr *2);
    int right = (curr *2) +1;

    int largest = curr;

    // kalau data dikiri lebih besar dari pada saat ini
    if(left <size && foods[left].price > foods[largest].price){
        largest = left;
    }
    if( right < size && foods[right].price > foods[largest].price){
        largest = right;
    }

    if(largest != curr){
        swap(foods[curr], foods[largest]);
        heapify(largest, size);
    }

}

void buildheap(){
    for(int i = currSize/2; i>=1; i--){
        heapify(i, currSize);
    }
}

void insertfood(const char *name , int price){
    strcpy(foods[currSize].name, name);
    foods[currSize].price = price;
    currSize++;
    buildheap();
}

void view(){
    for( int i = 1 ; i < currSize ; i++){
        printf("foods[%d] = %s %d\n" , i , foods[i].name , foods[i].price);
    }
}

Food peek(){
    if (currSize == 1){
        return foods[0];
    }
    return foods[1];
}

int searchfood(int price){
    for (int i = 1; i< currSize;i++){
        if(foods[i].price == price){
            return i;
        }
    }
    return -1;
}

void deletefood(int price){
    int index = searchfood(price);
    if(index == -1){
        printf("Data tidak ditemukan\n");
        return;
    }

    swap(foods[index], foods[currSize-1]);
}

void heapSort(){
    for(int i = currSize-1; i>=1; i--){
        swap(foods[1], foods[i]);
        heapify(1, i);
    }
}

int main(){

    insertfood("Sate Padang", 28000);
    insertfood("Sate Padang", 36000); 
    insertfood("Sate Padang", 10000);
    view();

    heapSort();
    view();
    return 0;
}