#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        double size = ceil((double)arr.size() / 4);

        for (auto &ele : mp)
        {
            if (ele.second >= size)
            {
                return ele.first;
            }
        }
        return 0;
    }
};
int main()
{
    return 0;
}