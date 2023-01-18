#include <stdio.h>
#include <stdlib.h>

int main(){
    // Data Structures
    // Bagaimana cara kita menggunakan data dengan baik?
    // Array : Sebuah data structure
    int x = 5;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // x1, x2, x3, x4, x5, x6, x7, x8, x9, x10
    // printf("%p", arr); // alamat index ke 0.
    // printf("%d\n", *(arr));
    // printf("%d\n", arr[0]);
    // printf("%d\n", *(arr+1));
    // printf("%d\n", *(arr+2));

    printf("%p\n", arr);
    printf("%p\n", arr+1);
    printf("%p\n", arr+2);
    
    return 0;
}