#include <bits/stdc++.h>
using namespace std;

void print_2d_vec(const vector<vector<int>> board)
{
    for (auto row : board)
    {
        for (auto val : row)
            cout << val << ' ';
        cout << '\n';
    }
}

bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    vector<vector<int>> int_board;
    vector<vector<int>> hfreq_row;
    vector<vector<int>> hfreq_col;
    vector<vector<int>> hfreq_box;
    for (int row = 0; row < n; row++)
    {
        int_board.push_back(vector<int>(n));
        hfreq_col.push_back(vector<int>(n));
        hfreq_box.push_back(vector<int>(n));
        for (int col = 0; col < n; col++)
        {
            int content = board[row][col] - '0';
            if (content < 1 or content > n)
                content = 0;
            int_board[row][col] = content;
        }
    }

    for (int row = 0; row < n; row++)
    {
        hfreq_row.push_back(vector<int>(n));
        for (int col = 0; col < n; col++)
        {
            int index_row = int_board[row][col];
            int index_col = int_board[col][row];
            if (index_row != 0 and (index_row >= 1 or index_row <= n))
                hfreq_row[row][index_row - 1]++;
            if (index_col != 0 and (index_col >= 1 or index_col <= n))
                hfreq_col[row][index_col - 1]++;
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int index = (row / 3) * 3 + col / 3;
            int index2 = int_board[row][col];
            if (index2 >= 1 and index2 <= 9)
                hfreq_box[index][index2 - 1]++;
        }
    }

    // cout << "board\n";
    // print_2d_vec(int_board);
    // cout << "freq row\n";
    // print_2d_vec(hfreq_row);
    // cout << "freq col\n";
    // print_2d_vec(hfreq_col);
    // cout << "freq box\n";
    // print_2d_vec(hfreq_box);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int inrow = hfreq_row[row][col];
            int incol = hfreq_col[row][col];
            int inbox = hfreq_box[row][col];
            if (inrow > 1 or incol > 1 or inbox > 1)
                return false;
        }
    }
    return true;
}

bool isvalidsudoku(vector<vector<char>> &board)
{
    int n = board.size();
    vector<vector<bool>> hfreq_row(n, vector<bool>(n, false));
    vector<vector<bool>> hfreq_col(n, vector<bool>(n, false));
    vector<vector<bool>> hfreq_box(n, vector<bool>(n, false));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int nev = board[row][col] - '1';
            int box_index = row / 3 * 3 + col / 3;
            if (nev < 0)
                continue;
            if (hfreq_row[row][nev] or hfreq_col[col][nev] or hfreq_box[box_index][nev])
                return false;
            hfreq_row[row][nev] = true;
            hfreq_col[col][nev] = true;
            hfreq_box[box_index][nev] = true;
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                                  {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
                                  {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
                                  {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    bool ans = isvalidsudoku(board);
    if (ans)
        cout << "true\n";
    else
        cout << "false\n";
}