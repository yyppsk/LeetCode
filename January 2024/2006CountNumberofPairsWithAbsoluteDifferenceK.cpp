#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int arr[201] = {};
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }

        for (int i = k + 1; i < 201; i++)
        {
            result += arr[i] * arr[i - k];
        }
        return result;
    }
};
int main()
{
    return 0;
}