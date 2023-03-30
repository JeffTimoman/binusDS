#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char MEMBERSHIP_TYPE[][20] = {" ", "Non-Member", "Bronze", 
			"Silver", "Gold", "Platinum"};

//Struct Struct Dasar
struct Customer{
	int id;
	char name[100];
	int level;
}customers[101];

struct Menu{
	int id;
	char name[100];
	int price;
}menus[101];

struct Order{
	int menuID;
	int quantity;
};

struct Node{
	char orderID[15];
	char name[100];
	Order orders[100];
	int level;
	Node *prev, *next;
}*HEAD = NULL, *TAIL = NULL;

Node* createNode(char orderID[], char name[], int level){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->orderID, orderID);
	strcpy(newNode->name, name);
	newNode->level = level;
	newNode->prev = newNode->next = NULL;
	for (int i = 0; i < 100; i++){
		newNode->orders[i].menuID = 0;
		newNode->orders[i].quantity = 0;
	}
	return newNode;
}

//Node Functions
void insert(Node *temp){
	if(!HEAD){
		HEAD = TAIL = temp;
	}else if(temp->level <= TAIL->level){
		TAIL->next = temp;
		temp->prev = TAIL;
		TAIL = temp;
	}else{
		Node* curr = HEAD;
		while(curr && curr->level >= temp->level){
			curr = curr->next;
		}
		
		if (curr == TAIL){
			TAIL->next = temp;
			temp->prev = TAIL;
			TAIL = temp;
		}else{
			temp->next = curr;
			temp->prev = curr->prev;
			temp->prev->next = temp;
			curr->prev = temp;
		}
	}
}

//Innitiation
void innit(){
	FILE *fp;
	fp = fopen("menus.txt", "r");
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, "%d#%[^#]#%d\n", &menus[i].id, menus[i].name, &menus[i].price);
		i++;
	}
	fclose(fp);
	
	fp = fopen("customers.txt", "r");
	i = 0;
	while(!feof(fp)){
		fscanf(fp, "%d#%[^#]#%d\n", &customers[i].id, customers[i].name, 
			&customers[i].level);
		i++;
	}
	
	fclose(fp);
}

//Printing
void printMenu(){
	puts("Hov's Fresh Concoction");
	puts("======================");
	puts("1. Add New Order");
	puts("2. View Order Queue");
	puts("3. Serve Order");
	puts("4. Exit");
	printf(">> ");
}

void printFoodDetail(){
	system("cls");
	puts(" ID  Name                        Price");
	for (int i = 0; i < 15; i++){
		printf(" %-3d %-27s %-5d\n", menus[i].id, menus[i].name, menus[i].price);
	}
	puts("");
}
//Supporting function
int getCustomerId(char name[]){
	for(int i = 0; i < 100; i++){
		if(strcmp(customers[i].name, name) == 0){
			return i;
		}
	}
	return -1;
}

char* generateId(int level){
	char temp[10];
	// sprintf(temp, "0%d-%c%c%d%d%d%d", level, rand() % 26 + 'A', rand() % 26 + 'A'
	// , rand() % 10 + '0', rand() % 10 + '0', rand() % 10 + '0', rand() % 10 + '0');
	temp[0] = '0';
	temp[1] = level + '0';
	temp[2] = '-';
	temp[3] = rand() % 26 + 'A';
	temp[4] = rand() % 26 + 'A';
	temp[5] = rand() % 10 + '0';
	temp[6] = rand() % 10 + '0';
	temp[7] = rand() % 10 + '0';
	temp[8] = rand() % 10 + '0';
	temp[9] = '\0';
	return temp;
}

//Switch-Case Menu
void addNewOrder(){
	system("cls");
	char name[100];
	printf(" Input customer name: ");
	scanf("%[^\n]", name); getchar();
	
	int index = getCustomerId(name);
	
	Node *temp = NULL;
	if (index != -1){
		puts(" Membership data found!");
		printf(" Customer ID    : %d\n", customers[index].id);
		printf(" Customer Name  : %s\n", customers[index].name);
		printf(" Membership Type: %s\n", MEMBERSHIP_TYPE[customers[index].level]);
		
		temp = createNode(generateId(customers[index].level), name, customers[index].level);
	}else{
		puts(" Membership data not found!");
		
		temp = createNode(generateId(0), name, 0);
	}
	
	puts("");
	printf("Press ENTER to order..."); getchar();
	
	int pick, counter = 0;
	do{
		printFoodDetail();
		printf(" Input Menu ID to be added [-1 to finish order]: ");
		scanf("%d", &pick); getchar();
		
		if (pick == -1){
			break;
		}
		if (pick < 0 || pick > 15){
			puts(" Invalid menu ID!"); getchar();
			continue;
		}
		
		int quantity;
		do{
			printf(" Input quantity for \"%s\": ", menus[pick-1].name);
			scanf("%d", &quantity); getchar();
			if (quantity <= 0){
				puts(" Invalid quantity (minimum 1)!"); getchar();
				continue;
			}
		}while(quantity < 0);
		
		printf(" \"%s\" x   %d added to the order.", menus[pick-1].name, quantity); getchar();
		
		Order order;
		order.menuID = pick;
		order.quantity = quantity;
		temp->orders[counter] = order;
		counter++;
	}while(pick != -1);
	
	system("cls");
 	puts("Please wait to be seated.");
 	puts("Below is your order details:");
 	int total = 0;
 	for (int i = 0; i < counter; i++){
 		printf("   %d x %-20s = %d\n", temp->orders[i].quantity, 
		 menus[temp->orders[i].menuID - 1].name, 
		 menus[temp->orders[i].menuID - 1].price * temp->orders[i].quantity);
		 total +=  menus[temp->orders[i].menuID - 1].price * temp->orders[i].quantity;
	 }
	 printf("Total order is %d\n\n", total);
	 printf("Press ENTER to back to Main Menu..."); getchar();
	 
	 insert(temp);
}

void printAll(){
	Node* temp = HEAD;
	int i = 1;
    while (temp){
        printf("Queue No.%02d\n", i);
        printf("Order ID : %s\n", temp->orderID);
        printf("Customer : %s\n", temp->name);
        printf("Order List:\n");
        int i = 0, total = 0;
		while (temp->orders[i].menuID != 0){
			printf("   %d x %-20s = %d\n", temp->orders[i].quantity, 
			 menus[temp->orders[i].menuID - 1].name, 
			 menus[temp->orders[i].menuID - 1].price * temp->orders[i].quantity);
			 total +=  menus[temp->orders[i].menuID - 1].price * temp->orders[i].quantity;
			i++;
		}
		temp = temp->next;
		i++;
	}
}

int main(){
	innit();
	srand(time(NULL));
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
