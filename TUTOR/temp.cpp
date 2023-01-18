#include<stdio.h>
#include<stdlib.h>

struct node{
	//data
	int val;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

//fungsi create node

struct node *createNode(int x){
	//block memory
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->val = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

int main(){
	// case 1 = double linked list masih kosong
	if(head == NULL && tail ==NULL){
		head = tail = createNode(5);
	}
	
	struct node *iter = head;
	while(iter){
		printf("%d\n", iter->val);
		iter = iter->next;
	}
	
	//case 2 -> insert last atau after tail
	
	struct node *temp = createNode(10);
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	printf("\n");
	iter = head;
	while(iter){
		printf("%d\n", iter->val);
		iter = iter->next;
	}
	printf("\n");
	
	struct node *iterBack = tail;
	while(iterBack){
		printf("%d\n", iterBack->val);
		iterBack = iterBack->prev;
	}
	return 0;
}