#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int coin_change(int M, int c[], int d)
{
    int best_num_coins[M + 1];
    best_num_coins[0] = 0; // pay 0 coin at the start

    for (int m = 1; m <= M; m++) // start from m upto M, the original value
    {
        // cout<<"to form " << m << " taka " <<endl;
        best_num_coins[m] = INF; // for comparison purpose
        for (int i = 0; i < d; i++)
        {
            if (m >= c[i]) // if value to fill >= current denomination
            {
                // cout<<" considering "<<c[i]<<endl;
                int nc = 1 + best_num_coins[m - c[i]];
                // cout<<": will need "<<nc<<" coins "<<endl;
                if (nc < best_num_coins[m])
                {
                    best_num_coins[m] = nc;
                }
            }
        }
    }

    return best_num_coins[M];
}

int main()
{

    int M = 46;                    // total tk
    int c[] = {1, 23, 25, 12, 10}; // coins
    int n = 5;                     // number of coins
    int d = coin_change(M, c, n);
    cout << "Need minimum " << d << endl;
}
