#include <bits/stdc++.h>
using namespace std;
vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                      vector<int> &r)
{
    vector<bool> result;
    if (nums.size() == 2)
    {
        return {true};
    }
    for (int i = 0; i < l.size(); i++)
    {
        int start = l[i], end = r[i];
        vector<int> temp;
        for (; start <= end; start++)
        {
            temp.push_back(nums[start]);
        }
        if (temp.size() == 2)
        {
            result.push_back(true);
        }
        else
        {
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            bool isArith = true;
            for (int k = 1; k < temp.size(); k++)
            {
                if ((temp[k] - temp[k - 1]) != diff && isArith)
                {
                    isArith = false;
                }
            }

            result.push_back(isArith);
        }
    }

    for (auto ele : result)
    {
        cout << ele << " ";
    }
    return result;
}
int main()
{
    vector<int> nums = {4, 6, 5, 9, 3, 7}, l = {0, 0, 2}, r = {2, 3, 5};
    checkArithmeticSubarrays(nums, l, r);
    return 0;
}