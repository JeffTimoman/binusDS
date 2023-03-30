#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char memberTypes[][20] = {" ", "Non-Member", "Bronze", "Silver", "Gold", "Platinum"};

struct Customer{
	int id;
	char name[100];
	int level;
}customers[101];

struct Menu{
	int id;
	char name[100];
	int price;
}menus[100];

struct Order{
	int menuID;
	int quantity;
};

struct Node{
	char orderID[15];
	char name[100];
	int level;
	Order orders[100];
	Node *prev, *next;
};

Node* createNode(char orderID[], char name[], int level){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->orderID, orderID);
	strcpy(newNode->name, name);
	newNode->level = level;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

char* generateId(int level){
	char temp[10];
	sprintf(temp, "0%d-%c%c%d%d%d%d", level, rand() % 26 + 'A', rand() % 26 + 'A'
	, rand() % 10 + '0', rand() % 10 + '0', rand() % 10 + '0', rand() % 10 + '0');
	temp[9] = '\0';
	return temp;
}

void innit(){
	FILE *fp = fopen("customers.txt", "r");
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, "%d#%[^#]#%d\n", &customers[i].id, 
			customers[i].name, &customers[i].level);
		i++;
	}
	fclose(fp);
	fp = fopen("menus.txt", "r");
	i = 0;
	while(!feof(fp)){
		fscanf(fp, "%d#%[^#]#%d\n", &menus[i].id, 
			menus[i].name, &menus[i].price);
		i++;
	}
	fclose(fp);
}

void printMenu(){
	puts("Hov's Fresh Concoction");
	puts("======================");
	puts("1. Add New Order");
	puts("2. View Order Queue");
	puts("3. Serve Order");
	puts("4. Exit");
	printf(">> ");
}

void printFoods(){
	system("cls");
	puts("ID  Name                        Price");
	for (int i = 0; i < 15; i++){
		printf("%-3d %-30s %-5d\n", menus[i].id, menus[i].name, menus[i].price);
	}
	puts("");
}

int getCustomerId(char name[]){
	for(int i = 0; i < 100; i++){
		if (strcmp(name, customers[i].name) == 0){
			return i;
		}
	}
	return -1;
}



void addNewOrder(){
	srand(time(NULL));
	char name[100];
	printf("Input customer name : ");
	scanf("%[^\n]", name); getchar();
	int index = getCustomerId(name);
	
	Node* temp = NULL;
	if (index != -1){
		puts("Membership data found!");
		printf("Customer ID    : %d\n", customers[index].id);
		printf("Customer Name  : %s\n", customers[index].name);
		printf("Membership Type: %s\n", memberTypes[customers[index].level]);
		temp = createNode(generateId(customers[index].level), name, 
			customers[index].level);
	}else{
		puts("Membership data not found");
		temp = createNode(generateId(1), name, 1);
	}
	puts("");
	printf("Press ENTER to order..."); getchar();
	
	int pick;
	
	do{
		printFoods();
		printf(" Input Menu ID to be added [-1 to finish order]:");
		scanf("%d", &pick); getchar();
		if (pick == -1){
			break;
		} 
		if (pick < 0 || pick > 15){
			puts("Invalid Menu ID!"); getchar();
			continue;
		}
		
		int quantity; int j = 0;
		do{
			printf("Input quantity for \"%s\"", menus[pick].name);
			scanf("%d", &quantity); getchar();
			if (quantity <= 0){
				puts("Invalid quantity (minimum 1)!"); getchar();
				continue;
			}
		}while(quantity <= 0);
		temp->orders[j].menuID = pick;
		temp->orders[j].quantity = quantity;
	}while(pick != -1);
	
}

int main(){
	innit();
	int menu;
	do{
		system("cls");
		printMenu();
		scanf("%d", &menu); getchar();
		switch(menu){
			case 1: 
				addNewOrder();
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4: 
				break;
			default:
				break;
		}
	}while(menu != 4);
	return 0;
}
