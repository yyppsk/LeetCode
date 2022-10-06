#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> getSumAbsoluteDifferences(vector<int> &nums)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            printf("%d + %d = %d\n", nums[i], nums[j], nums[i] - nums[j]);
            int temp = nums[i] - nums[j];
            if (temp < 0)
                temp *= -1;
            sum += temp;
        }
        result.push_back(sum);
        cout << endl;
    }
    for (auto i : result)
    {
        cout << i << " ";
    }
    return result;
}
int main()
{
    vector<int> arr = {2, 3, 5};
    getSumAbsoluteDifferences(arr);
    return 0;
}