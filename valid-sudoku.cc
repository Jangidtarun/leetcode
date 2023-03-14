#include <bits/stdc++.h>
using namespace std;

void print_2d_vec(const vector<vector<int>> board)
{
    for (auto row : board)
    {
        for (auto val : row)
            cout << val << " ";
        cout << '\n';
    }
}

bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    vector<vector<int>> int_board;
    vector<vector<int>> hfreq_col;
    for (int row = 0; row < n; row++)
    {
        int_board.push_back(vector<int>(n));
        hfreq_col.push_back(vector<int>(n));
        for (int col = 0; col < n; col++)
        {
            int content = board[row][col] - '0';
            if (content < 1 or content > 9)
                content = 0;
            int_board[row][col] = content;
        }
    }

    vector<vector<int>> hfreq_row;
    for (int row = 0; row < n; row++)
    {
        hfreq_row.push_back(vector<int>(n));
        for (int col = 0; col < n; col++)
        {
            int index = int_board[row][col];
            if (index != 0 and (index >= 1 or index <= 9))
            {
                hfreq_row[row][index - 1]++;
                hfreq_col[index - 1][row]++;
            }
        }
    }

    cout << "board\n";
    print_2d_vec(int_board);
    cout << "freq row\n";
    print_2d_vec(hfreq_row);
    cout << "freq col\n";
    print_2d_vec(hfreq_col);
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    isValidSudoku(board);
}