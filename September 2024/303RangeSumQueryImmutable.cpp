#include <bits/bits-stdc++.h>
using namespace std;
class NumArray
{
private:
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        prefix.push_back(0);
        for (int number : nums)
        {
            prefix.push_back(prefix.back() + number);
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main()
{
    return 0;
}