#include <iostream>
#include <vector>
using namespace std;
const int n = 9;

bool isValidSudoku(vector<vector<char>> &board)
{
    bool hbox[n][n] = {false};
    bool hrow[n][n] = {false};
    bool hcol[n][n] = {false};
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int boxindx = 3 * (row / 3) + col / 3;
            int val = board[row][col] - '1';
            if (val < 0)
                continue;
            if (hbox[boxindx][val] or hrow[row][val] or hcol[col][val])
                return false;
            hbox[boxindx][val] = true;
            hcol[col][val] = true;
            hrow[row][val] = true;
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> b = {{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '3', '.', '.', '5', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '8', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '1', '1', '6', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '1', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '7'},
                              {'.', '.', '.', '.', '.', '.', '.', '4', '.'}};

    bool ans = isValidSudoku(b);
    cout << (ans ? "yes" : "no") << '\n';
}
