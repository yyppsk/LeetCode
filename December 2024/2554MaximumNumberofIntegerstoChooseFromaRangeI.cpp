#include <bits/bits-stdc++.h>
using namespace std;

// Brute Binary Search
bool bs(vector<int> &banned, int number)
{
    int start = 0, end = banned.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (banned[mid] == number)
        {
            return true;
        }
        if (banned[mid] > number)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return false;
}

int maxCountBS(vector<int> &banned, int n, int maxSum)
{
    int count = 0;

    sort(banned.begin(), banned.end());
    for (int candidate = 1; candidate <= n; candidate++)
    {
        if (!bs(banned, candidate))
        {
            maxSum -= candidate;
            if (maxSum < 0)
                break;
            count += 1;
        }
    }

    return count;
}

// Sweep Method

int maxCountSweep(vector<int> &banned, int n, int maxSum)
{
    sort(banned.begin(), banned.end());

    int bannedIdx = 0, count = 0;

    for (int num = 1; num <= n && maxSum >= 0; num++)
    {
        if (bannedIdx < banned.size() && banned[bannedIdx] == num)
        {
            // Handle duplicate banned numbers
            while (bannedIdx < banned.size() && banned[bannedIdx] == num)
            {
                bannedIdx++;
            }
        }
        else
        {
            maxSum -= num;
            if (maxSum >= 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Sub Optimal 2N Space + O(N)
int maxCount_Brute(vector<int> &banned, int n, int maxSum)
{
    unordered_set<int> bannedSet(banned.begin(), banned.end());
    vector<int> candidates;
    for (int i = 1; i <= n; ++i)
    {
        if (bannedSet.find(i) == bannedSet.end())
        {
            candidates.push_back(i);
        }
    }

    int sum = accumulate(candidates.begin(), candidates.end(), 0);
    int result = candidates.size();

    if (sum <= maxSum)
    {
        return result;
    }
    int i = candidates.size() - 1;
    while (sum > maxSum && i >= 0)
    {
        sum -= candidates[i];
        result--;
        i--;
    }

    return result;
}

// Sub Optimal

int maxCount(vector<int> &banned, int n, int maxSum)
{
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    int sum = 0;
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {

        if (bannedSet.find(i) != bannedSet.end())
            continue;

        if (sum + i > maxSum)
            break;

        sum += i;
        result++;
    }

    return result;
}

int main()
{
    vector<int> banned = {8108, 8155};
    maxCount(banned, 2431, 7821);
    return 0;
}