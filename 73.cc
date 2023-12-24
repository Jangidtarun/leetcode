#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> zeros;
    for (int row = 0; row < matrix.size(); row++)
        for (int col = 0; col < matrix[0].size(); col++)
            if (matrix[row][col] == 0)
                zeros.push_back({row, col});

    for (auto &[r, c] : zeros)
    {
        matrix[r] = vector<int>(matrix[0].size(), 0);
        for (int row = 0; row < matrix.size(); row++)
            matrix[row][c] = 0;
    }
}

template <typename _tp>
void printmat(vector<vector<_tp>> &m)
{
    for (auto vec : m)
    {
        for (auto val : vec)
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> m = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    setZeroes(m);
    printmat(m);
}