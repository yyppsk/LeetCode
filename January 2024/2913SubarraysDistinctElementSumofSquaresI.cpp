#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                unordered_set<int> st;
                for (int k = i; k <= j; k++)
                {
                    st.insert(nums[k]);
                }
                int square = st.size() * st.size();
                cout << square << endl;
                count += square;
            }
        }

        return count;
    }
};
int main()
{
    return 0;
}