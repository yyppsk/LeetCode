#include <bits/bits-stdc++.h>
using namespace std;

int minIncrementForUnique2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int move = 0;
    // 1 2 2 2 3 7
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            move += (nums[i - 1] - nums[i] + 1);
            nums[i] = nums[i - 1] + 1;
        }
    }
    return move;
}

int minIncrementForUnique(vector<int> &nums)
{
    unordered_map<int, int> freq;
    priority_queue<int> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
        pq.push(nums[i]);
    }

    int move = 0;
    while (!pq.empty())
    {
        int currentNumber = pq.top();
        if (freq[currentNumber] == 1)
        {

            pq.pop();
        }
        else
        {
            move++;
            pq.pop();
            freq[currentNumber]--;
            currentNumber++;
            freq[currentNumber]++;

            pq.push(currentNumber);
        }
    }
    cout << move << "\n";
}

int main()
{
    vector<int> num = {3, 2, 1, 2, 1, 7};
    minIncrementForUnique(num);
    return 0;
}