#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> hp;
    for (int val : asteroids)
    {
        if (hp.empty() or val > 0)
            hp.push(val);

        else if (val < 0)
        {
            if (hp.top() + val == 0)
                hp.pop();
            else if (hp.top() < 0)
                hp.push(val);
            else
            {
                while (!hp.empty() and hp.top() > 0 and hp.top() + val < 0)
                    hp.pop();
                if (hp.empty() or hp.top() < 0)
                    hp.push(val);
                if (!hp.empty() and hp.top() + val == 0)
                    hp.pop();
            }
        }
    }

    vector<int> ans;
    while (!hp.empty())
    {
        ans.push_back(hp.top());
        hp.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> v = {-2, 2, 1, -2};
    vector<int> ans = asteroidCollision(v);
    for (int val : ans)
        cout << "val: " << val << " ";
    cout << endl;
}