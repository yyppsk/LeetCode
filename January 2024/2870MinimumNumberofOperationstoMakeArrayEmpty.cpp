#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int &num : nums)
        {
            count[num]++;
        }
        int result = 0;
        for (auto &ele : count)
        {
            if (ele.second == 1)
            {
                return -1;
            }
            if (ele.second % 3)
                result++;
            result += ele.second / 3;
        }
        return result;
    }
};
int main()
{
    return 0;
}