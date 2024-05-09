#include <bits/bits-stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    priority_queue<int> q;
    for (int i = 0; i < happiness.size(); i++)
    {
        q.push(happiness[i]);
    }

    long long sum = 0;
    int i = 0;
    while (k--)
    {
        int val = q.top() - i;
        i++;
        q.pop();

        if (val > 0)
        {
            sum += val;
        }
    }

    return sum;
}

int main()
{
    vector<int> v = {2, 3, 4, 5};

    cout << maximumHappinessSum(v, 3);
    return 0;
}