#include <stdio.h>
#include <string.h>
#define MAX 97


int main(){
    char string[100] = "naruto";
    int result = 0;
    for (int i = 0; i < strlen(string); i++){
        printf("%c : %d\n",string[i], string[i]);
        result += string[i];
    }
    
    printf("%d", result);
    printf("\n%d", result%MAX);
    return 0;
}