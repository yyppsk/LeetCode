#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)

{
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++)
    {
        int mul = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != i)
                mul *= nums[j];
        }
        answer.push_back(mul);
    }

    for (auto i : answer)
    {
        cout << i << " ";
    }
    return answer;
}
// Solution 1
vector<int> productExceptSelf2(vector<int> &nums)

{
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++)
    {
        int mul = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != i)
                mul *= nums[j];
        }
        answer.push_back(mul);
    }

    for (auto i : answer)
    {
        cout << i << " ";
    }
    return answer;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    productExceptSelf(nums);
    return 0;
}