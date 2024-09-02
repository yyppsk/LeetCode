#include <bits/bits-stdc++.h>
using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
    int n = chalk.size();
    int sum = 0;

    for (auto &i : chalk)
        sum += i;
    k = k % sum;

    int i = 0;
    while (i < n)
    {
        if (k < chalk[i])
            return i;
        k -= chalk[i];
        i++;
    }

    return 0;
}

int main()
{
    vector<int> arr = {3, 4, 1, 2};
    int k = 25;

    chalkReplacer(arr, k);

    return 0;
}