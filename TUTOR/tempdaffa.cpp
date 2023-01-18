#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int id;
    char name[100];
};

data person[1001];

int main(){
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %s", &person[i].id, person[i].name);
    }
    

    return 0;
}
