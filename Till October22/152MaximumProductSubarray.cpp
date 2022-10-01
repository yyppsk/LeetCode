#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxProductBrute(vector<int> &nums)
{
    int curr = nums[0];
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j <= nums.size() - 1; j++)
        {
            //printf("%d * %d = %d\n", curr, nums[j], curr * nums[j]);
            curr *= nums[j];
            //cout << "CURR : " << curr << endl;
            maxi = max(curr, maxi);
            //cout << "Max " << maxi << endl;
        }
        curr = nums[i + 1];
    }
    return maxi;
}
int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxProductBrute(arr);
    return 0;
}