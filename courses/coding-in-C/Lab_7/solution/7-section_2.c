#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO 1: Struct definition outside main
typedef struct Song
{
    double d;
    struct Song* pnext;
} Song;

Song* createNode(double value)
{
    Song* newNode = (Song*)malloc(sizeof(Song));
    if (!newNode) return NULL;
    newNode->d = value;
    newNode->pnext = NULL;
    return newNode;
}

void printList(Song* head)
{
    Song* current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%.0f -> ", current->d);
        current = current->pnext;
    }
    printf("NULL\n");
}
void ShiftNumbers (double* darray)
{
    char buff[1024];
    int b;
    do
    {
        printf("enter index:\n");

        if(!fgets(buff, sizeof buff, stdin))
        {
            return;
        }

         b = atoi(buff);
    } while (b == 0);

    if (b > 51)
    {
        printf("geht net\n");
    }
    else if(b < 0)
    {
        printf("geht net\n");
    }
    else
    {
        for (int j = 50; j > b; j--)
        {
            
            darray[j]= darray[j-1];
        }

        darray[b] = 12;

        for (int j = 0; j < 51; j++) 
        { 
            printf("%f ", darray[j]); 
        } 
        printf("\n");
        
    
    }



}

Song* InsertPos(Song* head, int pos, double d)
{
    if (pos < 1)
    {return head;}

    if( pos == 1)
    {
        Song* NewNode = createNode(d);
        NewNode->pnext = head;
        return NewNode;
    }

     Song* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->pnext;
    }

    if (curr == NULL)
        return head;

    Song* NewNode = createNode(d);
    NewNode->pnext = curr->pnext;
    curr->pnext = NewNode;

    return head; 
}

void printListToo(struct Song *head)
{
    struct Song *curr = head;
    while (curr != NULL)
    {
        printf("%f", curr->d);
        if (curr->pnext != NULL)
            printf(" -> ");
        curr = curr->pnext;
    }
    printf("\n");
}

void freeList(Song* head)
{
    Song* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->pnext;
        free(temp);
    }
}


int main()
{
    
// TODO 2: Define a starting pointer for the linked list called head.
    Song* head = NULL;

// TODO 4: Create 50 nodes and add them to the linked list,
//         starting with the pointer head.

    for (int i = 0; i < 50; i++)
    {
        Song* newNode = createNode((double)i);
        if (newNode)
        {
            newNode->pnext = head;
            head = newNode;
        }
    }

    printf("Created 50 nodes\n");
    printList(head);
    


// ------------------------------------------------------------
// TODO 5: Create an array with 51 elements.
// ------------------------------------------------------------

    double darray[51];

// ------------------------------------------------------------
// TODO 6: Fill array indices 0–49 with random integers.
// ------------------------------------------------------------
    srand(time(NULL));

    for (int i=0; i<49; i++)
    {
        int irand = rand();
        darray[i]= irand;
        printf("%f ",darray[i]);
    }

// ------------------------------------------------------------
// TODO 7: Generate an additional random number and insert it
//         at index 3 of the array
//         Shift all following elements by one position.
// ------------------------------------------------------------

ShiftNumbers(darray);



// ------------------------------------------------------------
// TODO 8: Insert a new node as the 3rd node in the linked list.
//         (Index 2 if zero-based indexing.)
//         Shift the remaining nodes accordingly.
// ------------------------------------------------------------

double d = 3, pos = 3;


 head = InsertPos(head, pos, d);

    
printListToo(head);

// ------------------------------------------------------------
// TODO 9: Print the array and the linked list.
// ------------------------------------------------------------



// ------------------------------------------------------------
// TODO 10: Add a comment in the code:
//          Which insertion is more time-consuming?
//          Array insertion or linked list insertion?

// TODO 11: Free all dynamically allocated memory
freeList(head);
return 0;
}