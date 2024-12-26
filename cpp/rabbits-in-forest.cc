#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    unordered_map<int, int> hmap;
    for (int i = 0; i < answers.size(); i++)
        hmap[answers[i]]++;
    vector<int> ans;
    vector<int> nr;
    for (auto val : hmap)
    {
        ans.push_back(val.first);
        nr.push_back(val.second);
    }
    int ansuar = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        int count = 0;
        while (nr[i] > 0)
        {
            nr[i] -= ans[i] + 1;
            count++;
        }
        ansuar += count * (ans[i] + 1);
    }
    return ansuar;
}

int main()
{
    vector<int> answers = {1, 1, 2};
    int output = numRabbits(answers);
    cout << output << endl;
}