#include <iostream>
#include <vector>
using namespace std;

// rotate around diagonal
void rotatedia(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        for (int j = i; j < matrix[0].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
}

// mirror around middle column
void mirrovert(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size() / 2; j++)
            swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
}

void rotate(vector<vector<int>> &matrix)
{
    rotatedia(matrix);
    mirrovert(matrix);
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
    vector<vector<int>> m = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    rotate(m);
    printmat(m);
}