#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    double d;
    struct Node* pnext;
}Node;

//Funktion um mehr Knoten zu erstellen

Node* createNode(double value)
{
    Node* NewNode= (Node*)malloc(sizeof(Node));
    if (!NewNode) return NULL;
    NewNode->d=value;
    NewNode->pnext=NULL;
    return NewNode;
}

Node* InsertPos(Node* head, int pos, double d)
{
    if(pos<0){return head;}

    if(pos==1)
    {
        Node* NewNode= createNode(d);
        NewNode->pnext=head;
        return NewNode;
    }
Node* curr = head;
for(int i=1; i<pos && curr != NULL; i++)
{
    curr= curr->pnext;
}

if(curr==NULL){return head;}

Node* NewNode= createNode(d);
NewNode->pnext= curr->pnext;
curr->pnext= NewNode;

return head;
}

//inserting a node at a specific pos and deleting a node at a specific pos

Node* DeletePos(Node* head, int pos)
{
    if(pos<0){return head;}

    if(pos==1)
    {
        Node* temp= head;
        head= head->pnext;
        free(temp);
        return head;
    }
    Node* curr= head;
    for(int i=1; i<pos-1 && curr->pnext != NULL; i++)
    {
        curr= curr->pnext;
    }
    if(curr->pnext == NULL){return head;}
    Node* temp= curr->pnext;
    curr->pnext= curr->pnext->pnext;
    free(temp);
    return head;
}

void printListToo(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%f", curr->d);
        if (curr->pnext != NULL)
            printf(" -> ");
        curr = curr->pnext;
            }
    printf("\n");
}

/*----------------------------------------------------------------------------------------*/
//Stack

typedef struct {
    int *stack;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *newStack = (Stack*)malloc(sizeof(Stack));
    newStack->stack = (int*)malloc(capacity * sizeof(int));
    newStack->top = -1;
    newStack->capacity = capacity;
    return newStack;
}

void push(Stack *s, int element) {
    if (s->top == s->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    s->stack[++s->top] = element;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top--];
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int size(Stack *s) {
    return s->top + 1;
}

void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%c ", s->stack[i]);
    }
    printf("\n");
}


/*----------------------------------------------------------------------------------------*/
//Queue
typedef struct {
    int *queue;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->queue = (int*)malloc(capacity * sizeof(int));
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->capacity = capacity;
    return newQueue;
}

void enqueue(Queue *q, int element) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->queue[++q->rear] = element;
}

int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front++];
}
 
int Peek(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front];
}
int isEmptyy(Queue *q) {
    return q->front > q->rear;
}

int Size(Queue *q) {
    return q->rear - q->front + 1;
}

void printQueue(Queue *q) {
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; ++i) {
        printf("%c ", q->queue[i]);
    }
    printf("\n");
}

int main() 
{
    Node* head = NULL;
for(int i = 0; i < 50; i++)
    {
        Node* newNode = createNode((double)i);
        if (newNode)
        {
            newNode->pnext = head;
            head = newNode;
        }
    }

    printListToo(head);

    head = InsertPos(head, 3, 3.0);
    printListToo(head);

    head = DeletePos(head, 3);
    printListToo(head);

    Stack *myStack = createStack(100);

    push(myStack, 'A');
    push(myStack, 'B');
    push(myStack, 'C');

    // Print initial stack
    printStack(myStack);

    printf("Pop: %c\n", pop(myStack));
    printf("Peek: %c\n", peek(myStack));
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", size(myStack));

    Queue *myQueue = createQueue(100);

    enqueue(myQueue, 'A');
    enqueue(myQueue, 'B');
    enqueue(myQueue, 'C');

    // Print initial queue
    printQueue(myQueue);

    printf("Dequeue: %c\n", dequeue(myQueue));
    printf("Peek: %c\n", Peek(myQueue));
    printf("isEmpty: %d\n", isEmptyy(myQueue));
    printf("Size: %d\n", Size(myQueue));

    return 0;
}