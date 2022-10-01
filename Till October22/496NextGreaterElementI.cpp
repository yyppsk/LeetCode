#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    stack<int> st;
    for (int i = nums1.size(); i > -1; i--)
    {
        int current = nums1[i];
        while (!st.empty() && st.top() <= current)
        {
        }
    }
}
int main()
{
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    nextGreaterElement(nums1, nums2);
    return 0;
}