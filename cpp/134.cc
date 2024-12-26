#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalgas = 0, totalcost = 0;
    int currentgas = 0, startindex = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        totalgas += gas[i];
        totalcost += cost[i];
        currentgas += gas[i] - cost[i];
        if (currentgas < 0)
        {
            startindex = i + 1;
            currentgas = 0;
        }
    }
    return (totalgas < totalcost) ? -1 : startindex;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int ans = canCompleteCircuit(gas, cost);
    cout << "ans: " << ans << endl;
}