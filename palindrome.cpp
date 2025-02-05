#include <bits/stdc++.h>
using namespace std;

int is_palindrome(int num, int temp)
{
    if (num == 0)
    {
        return temp;
    }
    temp = (temp * 10) + (num % 10);
    return is_palindrome(num / 10, temp);
}

int all_palindrome(int nums[], int first_num, int last_num)
{
    int temp_first = first_num;
    int temp_last = last_num;
    int i = 0;

    while (temp_first <= temp_last)
    {

        if (is_palindrome(temp_first, 0) == temp_first)
        {
            cout << temp_first << " ";
            nums[i] = temp_first;
            i++;
        }
        // cout << endl << nums[i];
        temp_first++;
    }
    return i;
}

void sum_palindrome(int nums[], int len)
{
    // int len = sizeof(nums)/sizeof(nums[0]);
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum = sum + nums[i];
    }
    cout << endl
         << "Sum : " << sum;
}

int main()
{
    int nums[100];
    int first_num;
    int last_num;

    cin >> first_num >> last_num;

    int len = all_palindrome(nums, first_num, last_num);
    sum_palindrome(nums, len);
    return 0;
}
