#include <stdio.h>

void findIndices(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int sum = arr[left] * arr[right];

        if (sum == target)
        {
            printf("Indices: %d, %d\n", left, right);
            return;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    printf("No indices found.\n");
}

int main()
{
    int arr[] = {2, 5, 7, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    findIndices(arr[], size, target);

    return 0;
}

int getSumOfDigits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void sortBySumOfDigits(int nums[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && getSumOfDigits(nums[j]) < getSumOfDigits(key))
        {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

int main()
{
    int nums[] = {123, 25, 12, 9, 100};
    int n = 5;

    sortBySumOfDigits(nums, n);

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}

void InsertAfter(struct Node **head, int element, int newVal, int k)
{
    if (*head == NULL)
    {
        printf("Error: Linked list is empty!\n");
        return;
    }

    struct Node *currentNode = *head;

    while (currentNode != NULL)
    {
        if (currentNode->data == element)
        {
            struct Node *newNode = createNode(newVal);

            if (currentNode->next != NULL || currentNode->data == k)
            {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                printf("New node with value %d inserted after %d.\n", newVal, element);
                return;
            }
            else
            {
                printf("Error: Element %d not found!\n", k);
                return;
            }
        }

        currentNode = currentNode->next;
    }

    printf("Error: Element %d not found!\n", element);
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
    }
    return head;
}
