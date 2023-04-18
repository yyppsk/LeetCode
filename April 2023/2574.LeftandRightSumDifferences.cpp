#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> leftRigthDifference(vector<int> &nums)
{
    
}
int main()
{
    vector<int> nums = {10, 4, 8, 3};
    vector<int> res = leftRigthDifference(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}