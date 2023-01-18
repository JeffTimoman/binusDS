#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//satu block node linked list
struct tnode{
	//menyimpan data
	int value;
	//menyimpan address
	struct tnode *next;
};

struct tnode *head = NULL;

//inisiasi node baru
struct tnode *initNode(int x){
	struct tnode ptr = (struct tnode)malloc(sizeof(struct tnode));
	ptr->value = x;
	ptr->next = NULL;
	return ptr;
}

void printList(){
	struct tnode *iter = head;
	while(iter->next){
		printf("%d\n", iter->value);
		iter = iter->next;
	}
}

void insertFront(int x){
	struct tnode *ptr = (struct tnode *)malloc(sizeof(struct tnode));
	if(head== tail){
		
	}else{
		ptr->next = head;
		head = ptr;
	}
	
	
}

//insert last
void insertLast(int x){
	struct tnode temp = (struct tnode)malloc(sizeof(struct tnode));
	temp->value = 30;
	temp->next = NULL;
	
	struct tnode *varBaru = head;
	while(varBaru ->next != NULL){
		varBaru = varBaru->next;
	}
	varBaru->next = temp;
	iter = head;
	while(iter ->next){
		printf("%d\n", iter->value);
		iter = iter->value;
	}
	
}

void delete(int x){
	//misal head =NULL = false
	//mengecek apakah element head ada
	//head->next == NULL;
	
	if(head && head->value == x && head->next ==NULL){
		free(head);
	}else if(head->value == x){
		struct tnode *iterDel = head;
		head = head-next>;
		iterDel ->next = NULL;
		free(iterDel);
	}else{
		struct tnode *iter = head;
		while(iter->next && iter->value != x){
			iter=  iter->next;
		}
		printf("element ada: %d\n", iter->value);
		struct tnode *iterDel = iter->next;
		iter->next = iter->next->next;
		free(iterDel);
	}
}
int main(){
	//isi data, inisiasi data linked list
	tail = head = initNode(8);
	//printf("%d- - %d", head, tail);
	
	//insert infront
	
	insertFront(30);
	
	//insert infront
	int x = 30;
	if(x<head){
		insertFront(x);
	}else if(x > tail){
		insertLast(x);
	}else{
		struct tnode *iter = head;
		while(iter -> next ->value < x){
			iter = iter ->next;
		}
		printf("data iter : %d\n", iter->value);
		struct tnode *node = initNode(x);
		node->next = iter->next->next;
		iter->next = node;
	}
	
	printList();
	printf("Tail value : %d", tail->value);
	
	
	
	printList();
	
	//iterasi
	struct tnode *iter = head;
	while(iter->next){
		printf("%d\n", iter->val);
		iter = iter->next;
	}
	
	//insert in the last
	insertLast(17);
	printList();
	
	
	//delete front node
	delete(int x);
	
	
}