#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int minHeap[1000];
int count = 0;

void swap(int index,int index2){
    int temp = minHeap[index];
    minHeap[index] = minHeap[index2];
    minHeap[index2] = temp;
}

int get_parent_index(int index){
    return(index-1)/2;
}

int get_left_child_index(int index){
    return 2*index + 1;
}

int get_right_child_index(int index){
    return 2*index + 2;
}

int get_min(){
    return minHeap[0];
}

void up_heap(int index){
    if( index == 0) return;
    int parent_index = get_parent_index(index);
    if ( minHeap[parent_index] <= minHeap[index] ) return;
    swap(index,parent_index);
    up_heap(parent_index);
}


void down_heap(int index){
    if (index >= count) return;
    int leftIndex = get_left_child_index(index);
    int rightIndex = get_right_child_index(index);
    int indexOfSmallest = index;

    if (leftIndex < count && minHeap[leftIndex] < minHeap[index]){
        indexOfSmallest = leftIndex;
    }

    if (rightIndex < count && minHeap[rightIndex] < minHeap[indexOfSmallest]){
        indexOfSmallest = rightIndex;
    }

    if (indexOfSmallest == index) return;
    swap(index,indexOfSmallest);
    down_heap(indexOfSmallest);

}

void push(int value){
    minHeap[count] = value;
    count++;
    up_heap(count-1);
}

// void pop(){
//     minHeap[0] = minHeap[count-1];
//     count--;
//     down_heap(0);
// }

int pop(){
    int removed = minHeap[0];
    minHeap[0] = minHeap[count-1];
    count--;
    down_heap(0);
    return removed;
}

int main(){
    srand(time(NULL));

    for (int i = 0; i < 10;i++){
        int value = rand() % 100;
        printf("%d is added!\n",value);
        push(value);
    }

    for (int i = 0; i < 10; i++){
        printf("%d is removed!\n",pop());
    }
    return 0;
}