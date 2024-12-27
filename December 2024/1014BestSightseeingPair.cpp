#include <bits/bits-stdc++.h>
using namespace std;

// Naive TLE
int maxScoreSightseeingPair_NAIVE(vector<int> &values)
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
    int maxSoFar = values[0];
    int maximum = 0;

    for (int j = 1; j < values.size(); j++)
    {
        maximum = max((values[j] - j) + maxSoFar, maximum);
        maxSoFar = max(maxSoFar, values[j] + j);
    }
    return maximum;
}
int main()
{
    vector<int> values = {8, 1, 5, 2, 6};
    maxScoreSightseeingPair(values);
    return 0;
}
