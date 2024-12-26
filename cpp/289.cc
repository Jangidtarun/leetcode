#include <iostream>
#include <vector>
using namespace std;

int neighbour(vector<vector<int>> &board, int i, int j)
{
    int ans = 0;
    for (int row = i - 1; row <= i + 1; row++)
        for (int col = j - 1; col <= j + 1; col++)
            if (row != i or col != j)
                if (row >= 0 and row < board.size() and col >= 0 and col < board[0].size())
                    ans += board[row][col];
    return ans;
}

void gameOfLife(vector<vector<int>> &board)
{
    vector<vector<int>> spare(board.size(), vector<int>(board[0].size()));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            int n = neighbour(board, i, j);
            if (board[i][j] and (n < 2 or n > 3))
                spare[i][j] = 0;
            else if (board[i][j] and (n == 2 or n == 3))
                spare[i][j] = 1;
            else if (!board[i][j] and n == 3)
                spare[i][j] = 1;
        }
    }
    board = spare;
}

int main()
{
}