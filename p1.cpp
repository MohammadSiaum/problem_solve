// problem - 1

#include <bits/stdc++.h>
using namespace std;

int calculateTotalDays(int tasks)
{

    if (tasks < 2)
    {
        return tasks;
    }

    return calculateTotalDays(tasks - 1) + calculateTotalDays(tasks - 2);
}

int main()
{
    int tasks;
    cout << "Input : ";
    cin >> tasks;

    int totalDays = calculateTotalDays(tasks);

    cout << "Output : " << totalDays << endl;

    return 0;
}
