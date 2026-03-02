#include <stdio.h>
#include <stdlib.h>

// 1.Create a program that asks the user for a integer N and then uses malloc() to reserve enough memory for this variable and save N at this address.

/*************************************************************************************************************************************************************/
int IntegerSaving (int a);
int IntegerSavingC (int b);
/********************************************************************************************************************************/
int IntegerSaving( int a)
{
    char buf[1024];

    do
    {
        printf("enter a number: ");

        if (!fgets(buf, 1024, stdin))
        {
            // reading input failed, give up:
            return 1;
        }

        // have some input, convert it to integer:
        a = atoi(buf);
    } 
    while (a == 0); // repeat until we got a valid number
    int* ptr = malloc(a * sizeof(int));
    if (ptr == NULL) return -1;

    // Populate the array with some example values
    for (int i = 0; i < a; i++)
        ptr[i] = i + 1;

    // Print the array
    for (int i = 0; i < a; i++)
        printf("%d ", ptr[i]);
    printf("\n");
    printf("You entered %d.\n", a);

    free(ptr);
    return 0;
}
/************************************************************************************************************************************/
 int IntegerSavingC (int b)
 {
    char buff[1024];

    do
    {
        printf("enter another number: ");

        if (!fgets(buff, sizeof buff, stdin))
        {
            return 1;
        }

        b = atoi(buff);
    }
    while(b == 0);

    int* ptrc = calloc(b, sizeof(int));
    if (ptrc == NULL) return -1;

    /* fill with square of index */
    for (int i = 0; i < b; i++)
    {
        ptrc[i] = i * i;
    }

    /* print values */
    for (int i = 0; i < b; i++)
    {
        printf("%d ", ptrc[i]);
    }
    printf("\nYou entered %d.\n", b);

    free(ptrc);


    ptrc = realloc(ptrc,2*sizeof(int));
    if(ptrc == NULL) return -1;

    free(ptrc);
    return 0;
 }

/************************************************************************************************************************************/

int main (void)
{
    IntegerSaving(0);      /* asks user for a number */
    IntegerSavingC(0);     /* asks user for a second number */
    return 0;
}

// 2.Now use the function calloc() to reserve memory for N integer variables (e.g. if N= 3 reserve memory for 3 integers).
// 3.Fill the created array of step2 with the square numbers of their index e.g. arr[i] = i*i
// 4.Afterwards, resize the array so it is twice as big (2 x N) and fill in the square numbers for the new indices.
// 5.Print the array.
// 6.Finally release the memory completely and end the program.
// 7.Comment into the code what the two main differences between calloc and malloc are.