#include <stdio.h>

struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
};
typedef struct Node node;

// Function prototypes
int menu();
node *insert_head(node *head, node *nn);
void printList(node *head);
node *createNode();
node *insert_tail(node *head, node *nn);
node *insert_nth(node *head, node *nn, int pos);
node *delete_head(node *head);
node *delete_tail(node *head);
node *delete_nth(node *head, int pos);

// Global variables
int list_size = 0;

int main()
{
    // printf("hello\n");
    node *head = NULL, *nn;
    int ch, pos;
    ch = menu();
    while (ch != 0)
    {
        if (ch == 1)
        {
            nn = createNode();
            head = insert_head(head, nn);
        }
        else if (ch == 2)
        {
            printf("enter position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= list_size + 1)
            {
                nn = createNode();
                head = insert_nth(head, nn, pos);
            }
            else
            {
                printf("invalid position.\n\n");
            }
        }
        else if (ch == 3)
        {
            nn = createNode();
            head = insert_tail(head, nn);
        }
        else if (ch == 4)
        {
            head = delete_head(head);
        }
        else if (ch == 5)
        {
            printf("enter position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= list_size)
            {
                head = delete_nth(head, pos);
            }
            else
            {
                printf("invalid position.\n\n");
            }
        }
        else if (ch == 6)
        {
            head = delete_tail(head);
        }
        else if (ch == 8)
        {
            printf("list size: %d\n\n", list_size);
        }
        else if (ch == 9)
        {
            printList(head);
        }
        else
        {
            printf("invalid choice. please try again...\n\n");
        }
        ch = menu();
    }
}

int menu()
{
    int ch;
    printf("1. insert (head)\n");
    printf("2. insert (nth)\n");
    printf("3. insert (tail)\n");
    printf("4. delete (head)\n");
    printf("5. delete (nth)\n");
    printf("6. delete (tail)\n");
    printf("8. print list size\n");
    printf("9. print list\n");
    printf("0. exit\n\n");
    printf("enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *createNode()
{
    node *temp;
    temp = new node();
    temp->next = NULL;
    printf("enter value: ");
    scanf("%d", &temp->data);
    return temp;
}

node *insert_head(node *head, node *nn)
{
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head->pre = nn;
        head = nn;
    }
    list_size++;
    return head;
}

node *insert_tail(node *head, node *nn)
{
    if (head == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // nn->pre = temp;
        temp->next = nn;
        nn->pre = temp;
    }
    list_size++;
    return head;
}

node *insert_nth(node *head, node *nn, int pos)
{
    if (pos == 1)
    {
        head = insert_head(head, nn);
    }
    else if (pos == list_size + 1)
    {
        head = insert_tail(head, nn);
    }
    else
    {
        node *temp;
        temp = head;
        while (pos - 2 > 0)
        {
            temp = temp->next;
            pos--;
        }
        nn->next = temp->next;
        temp->next = nn;
        nn->pre = temp;
        nn->next->pre = nn;
    }
    return head;
}

void printList(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return;
}

node *delete_head(node *head)
{
    node *temp;

    if (head == NULL)
    {
        printf("Nothing to delete.\n\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->pre = NULL;
        delete (temp);
        list_size--;
    }

    return head;
}

node *delete_tail(node *head)
{

    if (list_size < 2)
    {
        head = delete_head(head);
    }
    else
    {
        node *temp, *dlt;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        dlt = temp->next;
        delete (dlt);
        temp->next = NULL;
        list_size--;
    }

    return head;
}

node *delete_nth(node *head, int pos)
{
    if (pos == 1)
    {
        head = delete_head(head);
    }
    else if (pos == list_size)
    {
        head = delete_tail(head);
    }
    else
    {
        node *temp, *dlt;
        temp = head;

        while (pos-- - 2 > 0)
        {
            temp = temp->next;
        }
        dlt = temp->next;
        temp->next = dlt->next;
        dlt->next->pre = temp;
        delete (dlt);
        list_size--;
    }
    return head;
}
node *moreData(node *head)
{
    if (head->next == NULL)
    {
        head = delete_head(head);
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp ==)
                temp = temp->next;
        }
    }
}
node *countNum(node *head)
{
    int temNum;
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->value = temp->next->value)
        {
        }
    }
}