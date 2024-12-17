#include <bits/bits-stdc++.h>
using namespace std;

// brute
vector<int> nextGreaterElements_Brute(vector<int> &nums)
{
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int current = i;
        bool found = false;
        for (int j = i + 1; j < 2 * nums.size() - 1; j++)
        {
            if (nums[j % nums.size()] > nums[i] && current != j)
            {
                found = true;
                res[i] = nums[j % nums.size()];
                break;
            }
        }
        if (!found)
        {
            res[i] = -1;
        }
    }
    return res;
}

// Stack
vector<int> nextGreaterElements(vector<int> &nums)
{
    int size = nums.size();
    vector<int> res(size, -1);
    stack<int> st;

    for (int i = 2 * size - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % size])
        {
            st.pop();
        }

        if (i < size)
        {
            res[i] >= st.top() ? -1 : st.top();
        }

        st.push(nums[i % size]);
    }

    return res;
}
int main()
{
    return 0;
}