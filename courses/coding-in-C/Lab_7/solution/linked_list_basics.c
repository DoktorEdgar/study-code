#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Define struct Node using typedef
typedef struct Song
{
    double value;
    struct Song *next;
} Song;

// 3. Function to create a new node
Song *createNode(double value)
{
    Song *newNode = malloc(sizeof *newNode);
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    srand(time(NULL));

    // 2. Define head pointer
    Song *head = NULL;
    Song *current = NULL;

    // 4. Create 50 nodes and append to list
    for (int i = 0; i < 50; i++)
    {
        Song *newNode = createNode(rand());

        if (newNode == NULL)
        {
            printf("Stop programm.");
            return 1;
        }

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    // 5. Create array with 51 elements
    int arr[51];

    // 6. Fill array with 50 random integers
    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand();
    }

    // 7. Insert new random number
    int newValue = rand();

    // ---- ARRAY INSERTION at index 3 ----
    for (int i = 50; i > 3; i--)
    {
        arr[i] = arr[i - 1]; // shift right
    }
    arr[3] = newValue;

    // ---- LINKED LIST INSERTION at position 3 ----
    Song *newNode = createNode(newValue);

    Song *temp = head;

    // alternative: Node *temp = head->next->next;
    // Move to node before position 3 (index 2)
    for (int i = 0; i < 2; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    // Print array
    printf("Array:\n");
    for (int i = 0; i < 51; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print linked list
    printf("Linked List:\n");
    Song *iter = head;
    while (iter != NULL)
    {
        printf("%.0f ", iter->value);
        iter = iter->next;
    }
    printf("\n");

    // Free linked list memory
    Song *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
