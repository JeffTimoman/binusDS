#include<stdlib.h>
#include<stdio.h>

struct node{
	int val;
	struct node * next ; 
};

struct node *stack = NULL;
struct node *createNode(int val){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}
void push(int val){
	if(stack == NULL){
		stack = createNode(val);
	}else{
		struct node * temp = createNode(val);
		temp->next = stack;
		stack = temp;
	}
}

void printStack(){
	struct node * iter = stack;
	while(iter){
		printf("%d ", iter->val);
		iter = iter->next;
	}
	printf("\n");
}

struct node * pop(){
	if(stack){
		struct
	}
	// get top of stack
	struct node *delNode = stack;
	// copy value of top
	struct node *temp = delNode;
	//delete top stack
	stack = delNode->next;
	free(delNode);
	return temp;
}

struct node *top(){
	struct node * temp = stack;
	return temp;	
}

int main(){
	push(10);
	push(5);
	printStack();
	struct node * topData = top();
	printf("Top data: %d\n", topData->val);
	struct node *popped - pop();
	printStack();
	
	if (popped){
		printf("Pop Data: %d\n", popped->val);	
	}
	popped = pop();
	printStack();
	if(popped){
		printf("Pop Data: %d\n", popped->val);
	}
	popped = pop();
	if(popped){
		printf("Pop Data: %d\n", popped->val);
	}
	
    
}