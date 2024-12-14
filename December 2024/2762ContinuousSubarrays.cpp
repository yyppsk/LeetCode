#include <bits/bits-stdc++.h>
using namespace std;

// map & sliding window
long long continuousSubarrays(vector<int> &nums)
{
    long long answer = 0;
    int left = 0, right = 0;

    map<int, int> highlow;

    while (right < nums.size())
    {
        highlow[nums[right]] += 1;
        if (highlow[nums[right]] == 0)
        {
            highlow[nums[right]] += 1;
        }

        while (highlow.rbegin()->first - highlow.begin()->first > 2)
        {
            highlow[nums[left]] -= 1;
            if (highlow[nums[left]] == 0)
            {
                highlow.erase(nums[left]);
            }
            left += 1;
        }

        answer += (right - left) + 1;
        right += 1;
    }

    return answer;
}

int main()
{
    vector<int> v = {5, 4, 2, 4};
    cout << continuousSubarrays(v);
    return 0;
}