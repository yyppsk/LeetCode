#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        if (nums.size() % k != 0)
        {
            return false;
        }

        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (const auto &entry : count)
        {
            pq.push(entry.first);
        }

        while (!pq.empty())
        {
            int start = pq.top();
            pq.pop();

            int num = count[start];
            if (num > 0)
            {
                for (int i = 1; i < k; i++)
                {
                    if (count[start + i] < num)
                    {
                        return false;
                    }
                    else
                    {
                        count[start + i] -= num;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}