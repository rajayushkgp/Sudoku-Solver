#include <bits/stdc++.h>
#define n 16
using namespace std;
bool isSafeStep(int row, int col, int grid[n][n], int value)
{
    for (int i = 0; i < n; i++)
    {
        // row check
        if (grid[row][i] == value)
            return false;
        // column check
        if (grid[i][col] == value)
            return false;
        // 4x4 matrix check
        if (grid[4 * (row / 4) + i / 4][4 * (col / 4) + i % 4] == value)
            return false;
    }
    return true;
}
bool SolveSudoku(int grid[n][n])
{
    //traverse all element of matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //checking which box is blank
            if (grid[row][col] == 0)
            {
                //checking each value that is possible to enter in that box
                for (int value = 1; value <= n; value++)
                {
                    if (isSafeStep(row, col, grid, value))
                    {
                        grid[row][col] = value;
                        // recursive call to check for next possible solution
                        bool nextIterationPossible = SolveSudoku(grid);
                        if (nextIterationPossible)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            grid[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void takeInput(int grid[n][n])
{
    cout << "\nEnter the elements of unsolve sudoku (enter 0 in place of blank):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements (space separated) of Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] > 9 || grid[i][j] < 0)
            {
                cout << "\nWrong element entered!!\nEnter again\n";
                i--;
                break;
            }
        }
    }
    cout << "\n\n";
}
void print(int grid[n][n])
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}
int main()
{
    int input = 1;
    int grid[n][n];
    while (input)
    {
        takeInput(grid);
        if (SolveSudoku(grid))
        {
            cout<<"\nSolution Found\n";
            print(grid);
            cout << "\nSolved";
        }
        else
        {
            cout << "\nNo Solution Exist!!";
        }
        cout << "\nWant to solve another Sudoku of 9x9 ? (Enter 0/1): ";
        cin >> input;
    }
    return 0;
}
