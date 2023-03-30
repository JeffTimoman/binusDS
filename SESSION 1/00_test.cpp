#include <stdio.h>

int main(){
    int n = 10;
    // data type
    // variable name or Identifier
    // value
    // address ==> Focus pembahasan
    // scope

    // Print the address of n
    printf("%p\n", &n);

    // Pointer -> variable that stores address
    int *ptr_n = &n; 
    // Type of p is also should be the same as the type of n
    printf("%p\n", ptr_n);

    int **ptr_ptr_n = &ptr_n;
    printf("%p\n", ptr_ptr_n);
    printf("%p\n", &ptr_ptr_n);

    printf("%d\n", *ptr_ptr_n);
    printf("%d\n", **ptr_ptr_n);


    int arr[] = {1, 3, 5, 9};
    printf("%p\n", arr);
    printf("%d\n", *arr);
    printf("%p\n", (arr+1));
    printf("%d\n", *(arr+1));


    {
        int x = 5;
    }
    // Error : x is not defined in this scope
    // printf("%d", x);

    //Address is the location of memory
    // Vonn neuman
    
    return 0;
}