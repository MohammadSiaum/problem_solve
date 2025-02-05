#include <bits/stdc++.h>
using namespace std;

string generatePass(int id, int &evenCount)
{
    if (id == 0)
    {

        return "";
    }

    int digit = id % 10;

    if (digit % 2 == 0)
    {
        evenCount++;
        char digitChar = '0' + digit;
        return generatePassword(id / 10, evenCount) + digitChar;
    }
    else
    {
        return generatePassword(id / 10, evenCount);
    }
}

int main()
{

    int evenCount = 0;
    int identificationNum;
    cout << "Input : ";
    cin >> identificationNum;

    string password = generatePass(identificationNum, evenCount);

    cout << "Output : " << password << "#" << evenCount << endl;

    return 0;
}
