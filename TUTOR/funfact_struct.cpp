#include <stdio.h>

struct Dat{
    // int name; //4 byte
    double a; //8 byte
    int x; //4 byte
    int r;
};

int main(){
    printf("%d", sizeof(Dat));
    return 0;
}