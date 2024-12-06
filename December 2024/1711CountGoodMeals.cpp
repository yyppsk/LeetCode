#include <bits/bits-stdc++.h>
using namespace std;

bool check(int n)
{
    return n > 0 && ((n & (n - 1)) == 0);
}

// brute
int countPairsBrute(vector<int> &deliciousness)
{
    int count = 0;

    for (int i = 0; i < deliciousness.size(); i++)
    {
        for (int j = i + 1; j < deliciousness.size(); j++)
        {
            if (check(deliciousness[i] + deliciousness[j]))
            {
                count += 1;
            }
        }
    }

    return count + 1000000007;
}

// optimal
int countPairs(vector<int> &deliciousness)
{
    long long count = 0;
    unordered_map<long long, long long> freq;

    for (long long i = 0; i < deliciousness.size(); i++)
    {

        for (long long power = 0; power <= 21; power++)
        {
            long long target = pow(2, power) - deliciousness[i];
            if (target >= 0)
                if (freq.find(target) != freq.end())
                {
                    count += freq[target];
                }
        }

        freq[deliciousness[i]] += 1;
    }
    cout << count;
    return count % 1000000007;
}
int main()
{
    vector<int> deliciousness = {1, 1, 1, 3, 3, 3, 7};
    countPairs(deliciousness);
    return 0;
}
