#include <bits/bits-stdc++.h>
using namespace std;
vector<int> sumZero(int n)
{
    vector<int> result;

    for (int i = 1; i <= n / 2; i++)
    {
        result.push_back(-1 * i);
        result.push_back(i);
    }
    if (n % 2 == 1)
    {
        result.push_back(0);
    }

    return result;
}
int main()
{
    return 0;
}