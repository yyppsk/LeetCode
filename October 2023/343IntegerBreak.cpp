#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// Space O(N) + Time O(N * 2^E) + O(N)
void solve1(int num, int sum, vector<int> &ds, int k, int &maxi)
{

    cout << "Call for F(" << num << "," << sum << ")\n";
    if (num == 0 && ds.size() >= k)
    {
        int mul = 1;
        for (int i = 0; i < ds.size(); i++)
        {
            mul *= ds[i];
        }
        maxi = max(maxi, mul);
        return;
    }
    for (int i = 1; i <= num; i++)
    {
        if (sum - i < 0)
        {
            continue;
        }
        else
        {
            sum -= i;
            ds.push_back(i);
            solve1(num - i, sum, ds, k, maxi);
            sum += i;
            // cout << "Returning Back Sum " << sum << "\n";
            ds.pop_back();
        }
    }
    return;
}

// Time O(N * 2^E)
void solve2(int num, int sum, vector<int> &ds, int k, int &maxi, int prod, int t)
{

    // cout << "Call for F(" << num << "," << sum << ")\n";
    if (num == 0)
    {
        // int mul = 1;
        // for (int i = 0; i < ds.size(); i++)
        // {
        //     mul *= ds[i];
        // }
        maxi = max(maxi, prod);
        return;
    }
    for (int i = 1; i <= num; i++)
    {
        if (sum - i < 0)
        {
            continue;
        }
        else if (i != t) // if the product number is equal to the num itself then no need
        {
            sum -= i;
            prod *= i;
            solve2(num - i, sum, ds, k, maxi, prod, t);
            sum += i;
            // cout << "Returning Back Sum " << sum << "\n";
            prod /= i;
        }
    }
    return;
}

// Time O(N * 2^E) Memoization
vector<vector<int>> memo;

void initializeMemo(int n, int sum)
{
    memo.assign(n + 1, vector<int>(sum + 1, -1));
}
int solve(int num, int sum, int k, int prod, int t)
{
    // Base case
    if (num == 0)
    {
        return (k >= 2) ? prod : -1;
    }

    // Check if the result is already memoized
    if (memo[num][sum] != -1)
    {
        return memo[num][sum];
    }

    int maxi = -1;
    for (int i = 1; i <= num; i++)
    {
        if (sum - i >= 0 && i != t)
        {
            int result = solve(num - i, sum - i, k - 1, prod * i, t);
            if (result != -1)
            {
                maxi = max(maxi, result);
            }
        }
    }

    // Store the result in the memoization table
    memo[num][sum] = maxi;
    return maxi;
}
int main()
{
    vector<int> ds;
    int n = 10, sum = n, k = 2;
    int prod = 1, t = n;
    // int maxi = INT_MIN;
    //  solve2(n, sum, ds, k, maxi, prod, t);
    //  cout << maxi << endl;

    // Initialize the memoization table
    initializeMemo(n, sum);

    int maxi = solve(n, sum, k, prod, t);
    cout << maxi << endl;
    return 0;
}