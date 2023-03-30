#include <stdio.h>
#include <stdlib.h>
int main(){
    int n = 10;
    // Value --> 10
    // Address --> Memory --> Fokus disini
    // Tipe Data --> int
    // Identifier --> n
    // Scope 

    //Alamat dari n
    printf("%p\n", &n);

    //Pointer dari n
    int *ptr = &n;
    printf("%p\n", ptr); //Address dari n
    printf("%d\n", *ptr);

    //Pointer 
    int *(*ptr_ptr) = &ptr;
    printf("%p\n", ptr_ptr);

    //Pointer 
    int *(*(*ptr_ptr_ptr)) = &ptr_ptr;
    printf("%p\n", ptr_ptr_ptr);

    // Komputer --> RAM 
    /*
        RAM --> Bit
            int n = 10
            MEMORY --> NILAI 10, 
            NAMANYA --> N
            TIPE --> INTEGER (Ukuran byte yang mau diambil)
    */

    
    return 0;
}