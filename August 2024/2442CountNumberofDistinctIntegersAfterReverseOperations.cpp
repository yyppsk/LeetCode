#include <bits/bits-stdc++.h>
using namespace std;
int countDistinctIntegers(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        string convert = to_string(nums[i]);
        reverse(convert.begin(), convert.end());
        int number = stoi(convert);
        st.insert(number);
        st.insert(nums[i]);
    }

    return st.size();
}
int main()
{
    return 0;
}