#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
	char name[51];
	char NIM[9];
	Node *left, *right;
}*ROOT = NULL;

Node* createNode(char name[], char NIM[]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->NIM, NIM);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool validateNIM(char NIM[]){
	if(strlen(NIM) != 8){
		return false;
	}
	
	for(int i = 0; i < strlen(NIM); i++){
		if (NIM[i] < '0' || NIM[i] > '9'){
			return false;
		}
	}
	
	return true;
}

Node* insert(Node*curr, Node* input){
	if(!ROOT){
		ROOT = input;
		curr = input;
	}else if(!curr){
		curr = input;
	}else if(strcmpi(input->name, curr->name) > 0){
		curr->right = insert(curr->right, input);
	}else if(strcmpi(input->name, curr->name) < 0){
		curr->left = insert(curr->left, input);
	}else if(strcmpi(input->name, curr->name) == 0){
		puts("Student name already exists! updated NIM instead.");
		strcpy(curr->NIM, input->NIM);
	}
	
	return curr;
}

Node* del(Node* curr, char name[]){
	if(!curr){
		puts("Cannot delete because name doesn't exist!");
	}else if(strcmpi(name, curr->name) > 0){
		curr->right = del(curr->right, name);
	}else if(strcmpi(name, curr->name) < 0){
		curr->left = del(curr->left, name);
	}else{
		if (!curr->left && !curr->right){
			free(curr);
			curr = NULL;
		}else if(!curr->left){
			Node* temp = curr->right;
			free(curr);
			curr = temp;
		}else if(!curr->right){
			Node* temp = curr->left;
			free(curr);
			curr = temp;
		}else{
			Node* pre = curr->left;
			while(pre->right){
				pre = pre->right;
			}
			
			strcpy(curr->name, pre->name);
			strcpy(curr->NIM, pre->NIM);
			
			curr->left = del(curr->left, pre->name);
		}
	}
	
	return curr;
}

void insertStudent(){
	system("cls");
	puts("Insert Student\n");
	char name[51];
	do{
		printf("Enter name [3 - 50] : ");
		scanf("%[^\n]", name); getchar();
	}while(strlen(name) < 3 || strlen(name) > 50);
	
	char NIM[9];
	do{
		printf("Enter NIM [8 Characters, All Number] : ");
		scanf("%s", NIM); getchar();
	}while(!validateNIM(NIM));
	
	Node* temp = createNode(name, NIM);
	insert(ROOT, temp);
	printf("Student's been added!\n");
}

void deleteStudent(){
	system("cls");
	puts("Delete Student");
	
	char name[51];
	do{
		printf("Enter name to delete [3 - 50] : ");
		scanf("%[^\n]", name); getchar();
	}while(strlen(name) < 3 || strlen(name) > 50);
}

int main(){
	int menu;
	do{
		system("cls");
		puts("STUDENT THING MENU");
		puts("1. Insert Student");
		puts("2. Delete Student");
		puts("3. Exit");
		printf(">> ");
		scanf("%d", &menu); getchar();
		switch(menu){
			case 1: 
				insertStudent();
				break;
			case 2:
				deleteStudent();
				break;
			case 3: 
				break;
			default:
				break;
		}
		printf("Press ENTER to continue..."); getchar();
	}while(menu != 3);
	return 0;
}
