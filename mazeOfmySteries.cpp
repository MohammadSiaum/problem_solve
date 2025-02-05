// Q-3 : The Maze of Mysteries

#include <bits/stdc++.h>
using namespace std;

// maze size
const int N = 5;

int maze[N][N] = {
    {0, 1, 0, 0, 2},
    {0, 0, 0, 1, 0},
    {3, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool canFindTreasures(int x, int y, int movesLeft, int treasuresFound)
{
    if (movesLeft < 0 || treasuresFound >= 2)
    {
        return false;
    }

    if (maze[x][y] == 2)
    {
        treasuresFound++;
    }

    if (treasuresFound >= 2)
    {
        return true;
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    bool result = false;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && maze[newX][newY] != 1)
        {
            result = result || canFindTreasures(newX, newY, movesLeft - 1, treasuresFound);
        }
    }

    return result;
}

int main()
{
    int startX = 1;
    int startY = 0;

    if (canFindTreasures(startX, startY, 6, 0))
    {
        cout << "Eureka, I am rich" << endl;
    }
    else
    {
        cout << "Treasure hunt is boring" << endl;
    }

    return 0;
}
