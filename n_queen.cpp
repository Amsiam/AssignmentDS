
#include <bits/stdc++.h>

using namespace std;
int sol = 0;

void printSolution(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int **board, int row, int col, int n)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQUtil(int **board, int col, int n)
{
    if (col >= n)
    {
        sol++;
        printSolution(board, n);
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;

            solveNQUtil(board, col + 1, n);
            board[i][col] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    int **board;
    board = new int *[n];
    for (int i = 0; i < n; i++)
    {

        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    solveNQUtil(board, 0, n);

    if (sol == 0)
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}