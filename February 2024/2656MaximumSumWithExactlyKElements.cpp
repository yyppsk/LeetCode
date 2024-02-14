#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        priority_queue<int> heap;
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push(nums[i]);
        }
        int sum = 0;
        while (k > 0 && !heap.empty())
        {
            int m = heap.top();
            sum += m;
            heap.pop();
            heap.push(m + 1);
            k--;
        }
        return sum;
    }
};
int main()
{
    return 0;
}