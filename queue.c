#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Error: queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Enqueued item: %d\n", item);
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Error: queue is empty\n");
        return -1;
    }
    else
    {
        int item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("Dequeued item: %d\n", item);
        return item;
    }
}

void print()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue contents:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    char choice;
    int item;
    do
    {
        printf("Enter choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            printf("Enter item to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case '2':
            dequeue();
            break;
        case '3':
            print();
            break;
        case '4':
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != '4');
    return 0;
}