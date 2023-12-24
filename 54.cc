#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    enum _dir_
    {
        up,
        down,
        left,
        right
    };

    int m = matrix.size();
    int n = matrix[0].size();
    int ll = 0, rl = n - 1;
    int ul = 0, dl = m - 1;
    int elem = 0, total = m * n;
    _dir_ dir = right;
    vector<int> ans;
    while (elem < total)
    {
        switch (dir)
        {
        case right:
            for (int col = ll; col <= rl and elem < total; col++)
                ans.push_back(matrix[ul][col]), elem++;
            ul++;
            dir = down;
        case down:
            for (int row = ul; row <= dl and elem < total; row++)
                ans.push_back(matrix[row][rl]), elem++;
            rl--;
            dir = left;
        case left:
            for (int col = rl; col >= ll and elem < total; col--)
                ans.push_back(matrix[dl][col]), elem++;
            dl--;
            dir = up;
        case up:
            for (int row = dl; row >= ul and elem < total; row--)
                ans.push_back(matrix[row][ll]), elem++;
            ll++;
            dir = right;
        }
    }
    return ans;
}

int main()
{
}