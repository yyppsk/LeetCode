#include <bits/bits-stdc++.h>
using namespace std;

double minimumAverage(vector<int> &nums)
{
    int n = nums.size();
    double ans = INT_MAX;

    sort(nums.begin(), nums.end());

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        int sum = nums[i] + nums[j];
        double temp = sum / 2.0;

        ans = min(temp, ans);
        i++;
        j--;
    }

    return ans;
}
double minimumAveragePQ(vector<int> nums)
{
    int n = nums.size() / 2;
    double average;
    priority_queue<double, vector<double>, greater<double>> averages;
    sort(nums.begin(), nums.end());

    deque<int> dq;
    for (int i = 0; i < nums.size(); i++)
        dq.push_back(nums[i]);

    while (!dq.empty())
    {
        double maxi = (double)dq.front();
        double mini = (double)dq.back();
        dq.pop_front();
        dq.pop_back();
        double res = (double)(maxi + mini) / 2;
        averages.push(res);
    }

    return averages.top();
}

int main()
{
    cout << minimumAverage({14, 3, 6, 4, 6, 7, 15, 13, 14, 5, 7, 13});
}