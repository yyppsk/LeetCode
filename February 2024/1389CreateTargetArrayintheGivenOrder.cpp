#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    std::list<int> mylist;
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            insertelement(nums[i], index[i]);
        }

        vector<int> result(mylist.begin(), mylist.end());
        return result;
    }
    void insertelement(int number, int index)
    {
        auto it = mylist.begin();
        std::advance(it, index);
        mylist.insert(it, number);
    }
};
int main()
{
    return 0;
}