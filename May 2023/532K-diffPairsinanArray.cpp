#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;
int findPairs(vector<int> &nums, int k)
{
    int c = 0;
    /*Naive

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            printf("%d - %d (%d)= %d\n", nums[i], nums[j], abs(nums[i] - nums[j]), k);
            if (abs(nums[i] - nums[j]) == k)
            {
                c++;
            }
        }
    }
    */
    /*Two Pointers & sort*/
    class Solution
    {
    public:
        int findPairs(vector<int> &nums, int k)
        {
            sort(nums.begin(), nums.end());
            set<pair<int, int>> ans;
            int low = 0, high = 1;
            while (high < nums.size())
            {
                if (nums[high] - nums[low] == k)
                {
                    ans.insert({nums[low], nums[high]});
                    ++high, ++low;
                }
                else if (nums[high] - nums[low] > k)
                {
                    ++low;
                }
                else
                {
                    ++high;
                }
                if (low == high)
                    high++;
            }
            return ans.size();
        }
    };
}
int main()
{
    vector<int> n = {3, 1, 4, 1, 5};
    cout << findPairs(n, 2);
    return 0;
}