#include <bits/bits-stdc++.h>
using namespace std;

int counter;
int K;
void findSet(vector<int> &nums, int idx, unordered_map<int, int> &mp)
{

    if (idx == nums.size())
    {
        if (mp.size() > 0)
            counter++;
        return;
    }

    findSet(nums, idx + 1, mp);

    if (!mp[nums[idx] - K] && !mp[nums[idx] + K])
    {
        mp[nums[idx]]++;
        findSet(nums, idx + 1, mp);
        mp[nums[idx]]--;
    }
}

int beautifulSubsets(vector<int> &nums, int k)
{

    counter = 0;
    K = k;

    unordered_map<int, int> mp;

    findSet(nums, 0, mp);

    return counter;
}

int beautifulSubsets(vector<int> &nums, int k)
{

    counter = 0;
    K = k;

    unordered_map<int, int> mp;

    findSet(nums, 0, mp);

    return counter - 1;
}

class Solutution1
{

    void findsubset(vector<int> &nums, int k, vector<int> curr, int idx)
    {
        if (idx == nums.size())
        {
            if (curr.size() > 0)
            {
                counter++;
            }
            return;
        }

        bool canInclude = true;
        for (const int &num : curr)
        {
            if (abs(num - nums[idx]) == k)
            {
                canInclude = false;
                break;
            }
        }

        if (canInclude)
        {
            curr.push_back(nums[idx]);
            findsubset(nums, k, curr, idx + 1);
            curr.pop_back();
        }

        findsubset(nums, k, curr, idx + 1);
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {

        findsubset(nums, k, {}, 0);
        return 0;
    }
};

int main()
{
    vector<int> nums = {2, 4, 6};
    cout << beautifulSubsets(nums, 2);
    return 0;
}