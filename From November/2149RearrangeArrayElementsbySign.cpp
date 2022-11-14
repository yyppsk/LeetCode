#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> negatives;
    vector<int> result;
    for (int i : nums)
    {
        if (i < 0)
            negatives.push_back(i);
        else
            pos.push_back(i);
    }
    for (int i = 0; i < pos.size(); i++)
    {
        result.push_back(pos[i]);
        result.push_back(negatives[i]);
    }
    return result;
}
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> res = rearrangeArray(nums);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}