#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> m;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            int last = nums.back();
            int index = m[val];
            m[last] = index;
            nums[index] = last;
            nums.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

int main()
{
}