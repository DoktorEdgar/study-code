#include <stdio.h>
#include <string.h>

// int main(void) {
//     int x = 10;
//     int *p = &x;
//     int **pp = &p;

//     //TODO: complete the output statements
//     //Replace the ??? so that the value of x is printed:
//     printf("x = %d\n", x);
//     printf("x via p = %d\n", *p);
//     printf("x via pp = %d\n",**pp);

//     //Then change the value of x via pp to 42.
//     **pp = 42;

//    //Print x again and verify the result.
//     printf("x = %d\n", x);

//      //What are the types of the following expressions?
//      //x = variable x with 42
//      //p = pointer with the adress of x
//      //*p = pointer with the value of x
//      //pp = pointer with the adress of p
//      //*pp = pointer with the value of p (the adress of x)
//      //**pp = pointer with the value of x 

//     return 0;
// }

#include <stdio.h>
#include <string.h>

/*
1. Relationship between indexing ([]) and pointer dereferencing:

   In C, array indexing is simply pointer arithmetic.
   The expression:

        argv[i]

   is exactly the same as:

        *(argv + i)

   This means that indexing is just a more readable form
   of pointer dereferencing. Both access the i-th element
   of the array of pointers.


2. Relationship between arrays and pointers:

   In many situations, arrays "decay" into pointers.
   For example, in main():

        char **argv

   behaves like an array of strings, but technically it is
   a pointer to the first element of an array of char pointers.

   Each element argv[i] is itself a pointer to a char array
   (a C-string). Therefore:

        argv      → pointer to first argument
        argv[i]   → pointer to the i-th string
        *argv[i]  → first character of that string

   Arrays and pointers are not identical, but they are
   closely related and often used interchangeably in C.


------------------------------------------------------------
*/

int main(int argc, char **argv)
{


    // Ensure at least one argument (besides program name)
    if (argc < 2)
    {
        printf("Please provide at least one command-line argument.\n");
        return 1;
    }

    printf("--- Array Indexing Variant ---\n\n");

    // Variant 1: Using array indexing
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d\n", i);
        printf("  Address: %p\n", (void*)argv[i]);   // address of the string
        printf("  Content: %s\n", argv[i]);          // string content
        printf("  Length:  %lu\n", strlen(argv[i])); // number of characters
    }

    printf("\n--- Pointer Dereferencing Variant ---\n\n");

    // Variant 2: Using pointer dereferencing
    char **ptr = argv;   // do NOT modify argv directly

    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d\n", i);
        printf("  Address: %p\n", (void*)*ptr);      // address of current string
        printf("  Content: %s\n", *ptr);             // dereference pointer
        printf("  Length:  %lu\n", strlen(*ptr));    // string length

        ptr++;   // move to next argument
    }

    return 0;
}

