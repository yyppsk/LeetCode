#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_map<int, int> mp;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        int ele = nums2[i];
        while (!st.empty() && st.top() <= ele)
        {
            st.pop();
        }
        int res = st.empty() ? -1 : st.top(); // ya toh empty hua stack ya toh top pr sbse bda mil gya
        mp.insert({ele, res});
        st.push(ele);
    }
    for (auto i : nums1)
    {
        res.push_back(mp[i]);
    }
    return res;
}
int main()
{
    vector<int> nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
    nextGreaterElement(nums1, nums2);
    return 0;
}