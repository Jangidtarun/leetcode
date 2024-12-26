#include <bits/stdc++.h>
using namespace std;

pair<int, int> _dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char _tmp_rep = '-';
void dfs(vector<vector<char>> &b, int x, int y)
{
    if (x < 0 or x >= b.size() or y < 0 or y >= b[0].size())
        return;

    if (b[x][y] == 'O')
    {
        b[x][y] = _tmp_rep;
        for (auto &[_x, _y] : _dir)
            dfs(b, x + _x, y + _y);
    }
}

void solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] == 'O' and (i == 0 or j == 0 or i == board.size() - 1 or j == board[0].size() - 1))
                dfs(board, i, j);
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            board[i][j] = (board[i][j] == _tmp_rep) ? 'O' : 'X';
}

template <typename _t>
void printboard(vector<vector<_t>> v)
{
    for (auto vec : v)
    {
        for (auto val : vec)
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<vector<char>> v = {{'O', 'O', 'O', 'O', 'X', 'X'},
                              {'O', 'O', 'O', 'O', 'O', 'O'},
                              {'O', 'X', 'O', 'X', 'O', 'O'},
                              {'O', 'X', 'O', 'O', 'X', 'O'},
                              {'O', 'X', 'O', 'X', 'O', 'O'},
                              {'O', 'X', 'O', 'O', 'O', 'O'}};
    // vector<vector<char>> v = {{'X', 'X', 'X', 'X'},
    //                           {'X', 'O', 'O', 'X'},
    //                           {'X', 'X', 'O', 'X'},
    //                           {'X', 'O', 'X', 'X'}};
    cout << "input\n";
    printboard(v);
    solve(v);
    cout << "output\n";
    printboard(v);
}