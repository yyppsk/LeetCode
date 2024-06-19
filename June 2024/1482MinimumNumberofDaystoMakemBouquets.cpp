#include <bits/bits-stdc++.h>
using namespace std;

class Solution1
{
    int check(vector<int> &bloomDay, int m, int k, int day)
    {
        int count = 0;
        int totalBloom = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                totalBloom += (count / k);
                count = 0;
            }
        }

        totalBloom += (count / k);

        if (totalBloom >= m)
        {
            return true;
        }
        else
            return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (bloomDay.size() < m * k)
            return -1;
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minDay; day <= maxDay; day++)
        {
            if (check(bloomDay, m, k, day))
            {
                return day;
            }
        }
        return -1;
    }
};

int check(vector<int> &bloomDay, int m, int k, int day)
{
    int count = 0;
    int totalBloom = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            totalBloom += (count / k);
            count = 0;
        }
    }

    totalBloom += (count / k);

    if (totalBloom >= m)
    {
        return true;
    }
    else
        return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    long long totalBloomNeeded = m * 1LL * k * 1LL;
    if (bloomDay.size() < totalBloomNeeded)
        return -1;
    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

    while (minDay <= maxDay)
    {
        long long day = minDay + (maxDay - minDay) / 2;
        if (check(bloomDay, m, k, day))
        {
            maxDay = day - 1;
        }
        else
        {
            minDay = day + 1;
        }
    }

    return minDay;
}
int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2, k = 3;

    cout << minDays(bloomDay, m, k);
    return 0;
}