// Q-1 : Special Stack

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

int enchantedStack[MAX_SIZE];
int top = -1;

void push(int val)
{
    if (top < MAX_SIZE - 1)
    {
        top++;
        enchantedStack[top] = val;
    }
    else
    {
        cout << "Enchanted Stack is full : " << val << ".\n";
    }
}

int popEnd()
{
    if (top >= 0)
    {
        int val = enchantedStack[top];
        top--;
        return val;
    }
    else
    {
        cout << "Enchanted Stack is empty.\n";
        return -1;
    }
}

int popMagic()
{
    int removedEven = -1;
    while (top >= 0 && enchantedStack[top] % 2 != 1)
    {
        int val = popEnd();
        if (val % 2 == 0)
        {
            removedEven = val;
        }
    }
    return removedEven;
}

int main()
{
    push(10);
    push(20);
    push(33);
    push(40);
    push(50);
    push(60);

    int removedEven = popMagic();

    if (removedEven != -1)
    {
        cout << "Removed even element: " << removedEven << "\n";
    }
    else
    {
        cout << "No even element removed by popMagic.\n";
    }

    return 0;
}
