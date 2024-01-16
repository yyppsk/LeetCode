#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class RandomizedSet
{
public:
    unordered_map<int, int> map;
    vector<int> nums;
    RandomizedSet() {}

    bool insert(int val)
    {

        // return false if item present
        if (map.count(val))
            return false;

        nums.push_back(val);
        map[val] = nums.size() - 1;
        return true;
        // return true if item not present
    }

    bool remove(int val)
    {
        // return true if item present
        // return false if not present
        if (!map.count(val))
            return false;

        int last = nums.back();
        map[last] = map[val];
        nums[map[val]] = last;
        nums.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
    return 0;
}