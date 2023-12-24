#include <bits/stdc++.h>
using namespace std;

void changeColor(vector<vector<int>> &image, int i, int j, int pcolor, int ncolor)
{
    if (i < 0 || j < 0)
        return;
    if (i >= image.size() || j >= image[0].size())
        return;
    if (image[i][j] != pcolor)
        return;

    image[i][j] = ncolor;
    changeColor(image, i + 1, j, pcolor, ncolor);
    changeColor(image, i, j + 1, pcolor, ncolor);
    changeColor(image, i - 1, j, pcolor, ncolor);
    changeColor(image, i, j - 1, pcolor, ncolor);
    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int oldcolor = image[sr][sc];
    if (oldcolor != color)
        changeColor(image, sr, sc, oldcolor, color);
    return image;
}

int main()
{
}