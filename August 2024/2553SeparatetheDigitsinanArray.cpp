#include <bits/bits-stdc++.h>
using namespace std;

vector<int> separateDigits(vector<int> &nums)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        string number = to_string(nums[i]);
        for (int k = 0; k < number.size(); k++)
        {
            int currentNumber = (number[k] - '0');
            result.push_back(currentNumber);
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {13, 25, 83, 77};
    separateDigits(nums);
    return 0;
}