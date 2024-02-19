#include <bits/stdc++.h>
using namespace std;

class Greedy
{
    int maxSatisfaction(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] + total > 0; --i)
        {
            total += A[i];
            res += total;
        }
        return res;
    }
};

class solution1Recursive
{
    int maxi = 0;
    int subsequence(vector<int> &satisfaction, int idx, int sum, int &Liketimecoefficient)
    {
        if (idx == satisfaction.size())
        {
            maxi = max(maxi, sum);
            return maxi;
        }

        sum += (satisfaction[idx] * Liketimecoefficient);
        Liketimecoefficient++;
        subsequence(satisfaction, idx + 1, sum, Liketimecoefficient);

        Liketimecoefficient--;
        sum -= (satisfaction[idx] * Liketimecoefficient);

        subsequence(satisfaction, idx + 1, sum, Liketimecoefficient);

        return maxi;
    }
};

int KPrecur(vector<int> &satisfaction, int idx, int time)
{
    if (idx >= satisfaction.size())
        return 0;
    int includes = (satisfaction[idx] * time) + KPrecur(satisfaction, idx + 1, time + 1);

    int excludes = KPrecur(satisfaction, idx + 1, time);

    int maxi = max(includes, excludes);
    return maxi;
}

int n;
int memo[501][501];

int KPmemo(vector<int> &satisfaction, int idx, int time)
{
    if (idx >= satisfaction.size())
        return 0;

    if (memo[idx][time] != -1)
    {
        return memo[idx][time];
    }
    int includes = (satisfaction[idx] * time) + KPmemo(satisfaction, idx + 1, time + 1);

    int excludes = KPmemo(satisfaction, idx + 1, time);

    int maxi = max(includes, excludes);
    return memo[idx][time] = maxi;
}

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    int size = satisfaction.size();
    memset(memo, -1, sizeof(memo));
    int factor = 1;
    return KPrecur(satisfaction, 0, factor);
}

int main()
{
    vector<int> arr = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(arr);
    return 0;
}