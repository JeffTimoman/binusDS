#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 100

struct Node{
	int key;
	char name[100];
	char phone[100];
	int age;
	char room[15];
	int day;
	char id[6];
	Node *next;
};

struct HashTable{
	int dataCount = 0;
	Node *HEAD = NULL;
	Node *TAIL = NULL;
}hashTables[MAX];

int hashFunction(char id[]){
	int temp = 0;
	temp += id[2] - '0';
	temp += id[3] - '0';
	temp += id[4] - '0';
	temp %= 100;
	
	return temp;
}

Node* createNode(char name[], char phone[], int age, char room[], int day, char id[]){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->age = age;
	strcpy(newNode->room, room);
	newNode->day = day;
	strcpy(newNode->id, id);
	newNode->next = NULL;
	newNode->key = hashFunction(id);
	return newNode;
}

void insert(Node* temp){
	int key = temp->key;
	
	if(hashTables[key].dataCount == 0){
		hashTables[key].HEAD = hashTables[key].TAIL = temp;
	}else{
		hashTables[key].TAIL->next = temp;
		hashTables[key].TAIL = temp;
	}
	hashTables[key].dataCount++;
}

void del(char id[]){
	int key = hashFunction(id);
	if(hashTables[key].dataCount == 0){
		puts("");
		puts("+--------------------------------------+");
		puts("| Failed to Delete, There is No Data ! | ");
		puts("+--------------------------------------+");
		puts("");
		return;
	}else if(strcmp(hashTables[key].HEAD->id, id) == 0){
		
		puts("+==========================================+");
		printf("| BookingID %s is Successfully Deleted! |\n", id);
		puts("+==========================================+\n");
		if (hashTables[key].HEAD == hashTables[key].TAIL){
			free(hashTables[key].HEAD);
			hashTables[key].HEAD = hashTables[key].HEAD = NULL;
		}else{
			Node* dele = hashTables[key].HEAD;
			hashTables[key].HEAD = hashTables[key].HEAD->next;
			free(dele);
		}
		hashTables[key].dataCount--;
	}else if(strcmp(hashTables[key].TAIL->id, id) == 0){
		
		puts("+==========================================+");
		printf("| BookingID %s is Successfully Deleted! |", id);
		puts("+==========================================+\n");
		
		Node *curr = hashTables[key].HEAD;
		while(curr->next != hashTables[key].TAIL){
			curr = curr->next;
		}
		curr->next = NULL;
		free(hashTables[key].TAIL);
		hashTables[key].TAIL = curr;
		hashTables[key].dataCount--;
	}else{
		Node* curr = hashTables[key].HEAD;
		Node* parent = NULL;
		while(strcmp(curr->id, id) != 0){
			parent = curr;
			curr = curr->next;
		}
		
		if(!curr){
			puts("");
			puts("+--------------------------------------+");
			puts("| Failed to Delete, There is No Data ! | ");
			puts("+--------------------------------------+");
			puts("");
			puts("Ini Jalan");
			return;
		}
		
		parent->next = curr->next;
		free(curr);
		hashTables[key].dataCount--;
	}
	
}

//Additional Function
void printMenu(){
	puts("+--------------------+");
	puts("| Hotel GrAnsylvania |");
	puts("+--------------------+");
	puts("1. Booking Hotel");
	puts("2. View Bookings");
	puts("3. Delete Booking");
	puts("4. Exit");
	printf(">> ");	
}
char* generateID(char a, char b){
	char id[6];
	sprintf(id, "%c%c%d%d%d", a, b, rand() %9, rand() % 9, rand() %9);
	id[5] = '\0';
	return id;
}

//validation
bool validateName(char name[]){
	if (strlen(name) < 3 || strlen(name) > 30){
		puts("Full name length must between 3 and 30");
		return false;
	}
	
	return true;
}

bool validatePhone(char phone[]){
	if (phone[0] != '+' || phone[1] != '6' || phone[2] != '2' || phone[3] != ' '){
		puts("Phone number must begin with '+62', contains with at least 1 space and the length must be (11 Exclue +62 and space)");
		return false;
	}
	
	if (strlen(phone) != 15){
		puts("Phone number must begin with '+62', contains with at least 1 space and the length must be (11 Exclue +62 and space)");
		return false;	
	}
	return true;
}

bool validateRoom(char room[]){
	if (strcmp(room, "Deluxe") == 0){
		return true;
	}
	
	if (strcmp(room, "Regular") == 0){
		return true;
	}
	
	if (strcmp(room, "Suite") == 0){
		return true;
	}
	
	puts("Room Type must be either Regular or Deluxe or Suite (Case Sensitive)");
	return false;
}

bool validateBookID(char id[]){
	if (strlen(id) != 5){
		return false;
	}
	
	if (id[0] < 'A' || id[0] > 'Z'){
		return false;
	}
	if (id[1] < 'A' || id[1] > 'Z'){
		return false;
	}
	if (id[2] < '0' || id[0] > '9'){
		return false;
	}
	if (id[3] < '0' || id[3] > '9'){
		return false;
	}
	if (id[4] < '0' || id[4] > '9'){
		return false;
	}
	
	return true;
	
}

//Switch Case Main Function
void bookHotel(){
	char name[100];
	do{
		printf("Input Full Name [3..30] : ");
		scanf("%[^\n]", name); getchar();
	}while(!validateName(name));
	
	char phone[100];
	do{
		printf("Input Phone Number : "); 
		scanf("%[^\n]", phone); getchar();
	}while(!validatePhone(phone));
	
	int age;
	do{
		printf("Input Age [Minimum 18] : ");
		scanf("%d", &age); getchar();
		if (age < 18){
			puts("Age must be minimum 18");
		}
	}while(age < 18);
	
	char room[15];
	do{
		printf("Input Room Type [Regular | Deluxe | Suite ] (Case sensitive) : ");
		scanf("%[^\n]", room); getchar();
	}while(!validateRoom(room));
	
	int day; 
	do{
		printf("Input How Many Night You Will Stay [1..30] : ");
		scanf("%d", &day); getchar();
		if(day < 1 || day > 30){
			puts("You can't stay less than 1 night or more than 30 nights.");
		}
	}while(day < 1 || day > 30);
	
	char id[10];
	strcpy(id, generateID(toupper(room[0]), toupper(room[1])));
	
	Node* temp = createNode(name, phone, age, room, day, id);
	insert(temp);
	
	puts("");
	puts("+==========================================+");
	printf("| Booking ID   : %-25s |\n", id);
	puts("+==========================================+");
	printf("| Full Name    : %-25s |\n", name);
	printf("| Phone Number : %-25s |\n", phone);
	printf("| Room Type    : %-25s |\n", room);
	printf("| Night Stay   : %-25d |\n", day);
	puts("+==========================================+");
	puts("");
}

void viewBookings(){
	int counter = 0;
	for (int i = 0; i < MAX; i++){
		counter += hashTables[i].dataCount;
	}
	
	if(counter == 0){
		puts("\n+-----------------------+");
		puts("| There is no booking ! |");
		puts("+-----------------------+\n");
		return;
	}
	
	for (int i = 0; i < MAX; i++){
		if (hashTables[i].dataCount == 0){
			continue;
		}
		
		Node* curr = hashTables[i].HEAD;
		while(curr){
			puts("");
			puts("+==========================================+");
			printf("| Booking ID   : %-25s |\n", curr->id);
			puts("+==========================================+");
			printf("| Full Name    : %-25s |\n", curr->name);
			printf("| Phone Number : %-25s |\n", curr->phone);
			printf("| Room Type    : %-25s |\n", curr->room);
			printf("| Night Stay   : %-25d |\n", curr->day);
			puts("+==========================================+");
			puts("");
			curr = curr->next;
		}
	}
}

void deleteBooking(){
	viewBookings();
	char id[6];
	printf("Enter Booking ID (Case Sensitive) : ");
	scanf("%[^\n]", id); getchar();
	if(strlen(id) != 5){
		puts("");
		puts("+--------------------------------------+");
		puts("| Failed to Delete, There is No Data ! | ");
		puts("+--------------------------------------+");
		puts("");
		return;
	}
	
	del(id);
	
}

int main(){
	srand(time(NULL));
	int menu;
	do{
		printMenu();
		scanf("%d", &menu); getchar();
		switch(menu){
			case 1: 
				puts("Booking Hotel!");
				bookHotel();
				break;
			case 2: 
				puts("View Bookings");
				viewBookings();
				break;
			case 3: 
				puts("Delete Booking");
				deleteBooking();
				break;
			case 4:
				puts("Exit!");
				break; 
			default :
				break;
		}
		printf("Press ENTER to continue..."); getchar();
	}while(menu != 4);
	return 0;
}
