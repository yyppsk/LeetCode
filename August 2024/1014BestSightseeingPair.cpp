#include <bits/bits-stdc++.h>
using namespace std;

// Brute Force
int maxScoreSightseeingPair_1(vector<int> &values)
{
    int maximum = 0;
    for (int i = 0; i < values.size(); i++)
    {
        int currSum = 0;
        for (int j = i + 1; j < values.size(); j++)
        {
            currSum = ((values[i] + values[j]) + (i - j));

            maximum = max(maximum, currSum);
        }
    }

    return maximum;
}

int maxScoreSightseeingPair(vector<int> &values)
{
    int n = values.size();
    vector<int> dp(n);
    dp[0] = values[0];
    int maxVal = 0;
}
int main()
{
    vector<int> val = {8, 1, 5, 2, 6};
    cout << maxScoreSightseeingPair(val);
    return 0;
}