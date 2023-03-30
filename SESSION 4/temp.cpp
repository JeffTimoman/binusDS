#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int value;
    char key[25];
    long long int hashed;
    char buffer[50];
    sprintf(buffer, "%lld", 99*99);
    printf("%s\n", buffer);

    if(strlen(buffer)%2 == 1){
        int mid = strlen(buffer)/2;
        strncpy(key, &buffer[mid], 1);
    }else{
        int mid = strlen(buffer)/2 - 1;
        strncpy(key, &buffer[mid], 1);
        strncpy(key + 1, &buffer[mid + 1], 1);
    }
    key[2] = '\0';

    char *strBuff;
    printf("%s\n", key);
    hashed = atoi(key);
    printf("%lld\n", hashed);

    printf("%c\n", buffer[1]);
    return 0;
}
