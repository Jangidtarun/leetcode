#include <bits/stdc++.h>
using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
	vector<bool> ans;
	for (int i = 0; i < l.size(); i++)
	{
		if (r[i] - l[i] == 1)
		{
			ans.push_back(true);
			continue;
		}
		vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);

		sort(tmp.begin(), tmp.end());

		bool flag = true;
		int d = tmp[1] - tmp[0];
		for (int j = 1; j < tmp.size(); j++)
		{
			if (tmp[j] - tmp[j - 1] != d)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			ans.push_back(true);
		else
			ans.push_back(false);
	}
	return ans;
}

int main()
{
	vector<int> nums = {4, 6, 5, 9, 3, 7};
	vector<int> l = {0, 0, 2};
	vector<int> r = {2, 3, 5};

	vector<bool> ans = checkArithmeticSubarrays(nums, l, r);
	for (const bool &val : ans)
		cout << (val ? "true" : "false") << endl;
}