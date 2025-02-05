#include <stdio.h>

void matric_multi(int arr1[][10], int arr2[][10], int m, int n)
{
    int result[m][m];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int m, n;
    scanf("%d %d", &m, &n);

    int arr1[10][10];
    int arr2[10][10];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    matric_multi(arr1, arr2, m, n);
}
