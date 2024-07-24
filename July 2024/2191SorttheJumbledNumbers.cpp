#include <bits/bits-stdc++.h>
using namespace std;

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    vector<pair<int, int>> result;

    for (int i = 0; i < nums.size(); i++)
    {
        string currentNumber = to_string(nums[i]);
        for (int j = 0; j < currentNumber.size(); j++)
        {
            int index = int(currentNumber[j]) - '0';
            currentNumber[j] = mapping[index] + '0';
        }

        result.push_back({stoi(currentNumber), i});
    }
    sort(result.begin(), result.end(),
         [](pair<int, int> a, pair<int, int> b)
         {
             return a.first < b.first;
         });

    vector<int> sortedNums(nums.size());
    for (int i = 0; i < result.size(); ++i)
    {
        sortedNums[i] = nums[result[i].second];
    }

    return sortedNums;
}
int main()
{
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, nums = {991, 338, 38};
    vector<int> sortedNums = sortJumbled(mapping, nums);

    for (const int &num : sortedNums)
    {
        cout << num << " ";
    }
    return 0;
}