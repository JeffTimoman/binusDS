#include <string.h>
#include <ctype.h>
#include <stdio.h>

//bool validateDouble(char title[]){
//	for (int i = 0; i < MAX; i++){
//		Node *curr = hashTables[i].HEAD;
//		while(curr){
//			if (strcmp(curr->title, title) == 0){
//				return false;
//			}
//			curr = curr->next;
//		}
//	}
//	return true;
//}
//
//bool validateAuthorName(char name[]){
//	if (strlen(name) < 3 || strlen(name) > 25){
//		return false;
//	}
//	
//	if (name[0] != 'M'){
//		return false;
//	}
//	
//	if (name[1] != 'r'){
//		return false;
//	}
//	
//	if( name[2] == '.' && name[3] == ' '){
//		return true;
//	}
//	
//	if (name[2] == 's' && name[3] == '.' && name[4] == ' '){
//		return true;
//	}
//	
//	return false;
//}
//
//bool validateISBN(char ISBN[]){
//	
//	if(strlen(ISBN) < 10 || strlen(ISBN) > 13){
//		return false;
//	}
//	
//	for (int i = 0; i < strlen(isbn); i++){
//		if (ISBN[i] < '0' || ISBN[i] > '9'){
//			return false;
//		}
//	}
//	return true;
//}

int main(){
	char a[10] = "Geeks";
	char b[10] = "geeks";
	printf("%d", strcmpi(a, b));
	
	return 0;
}
