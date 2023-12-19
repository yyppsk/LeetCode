#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// Math solution with intution of minifying the sub matrix
int maxCount(int m, int n, vector<vector<int>> &ops)
{
    int minA = INT_MAX, minB = INT_MAX;
    for (int i = 0; i < ops.size(); i++)
    {
        int a = ops[i][0];
        int b = ops[i][1];

        minA = min(a, minA);
        minB = min(b, minB);
    }
    return minA * minB;
}
// Memory Limit bruteforce
int maxCount2(int m, int n, vector<vector<int>> &ops)
{
    if (ops.size() == 0)
    {
        return m * n;
    }
    int x, y;
    int maxi = INT_MIN;
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < ops.size(); i++)
    {
        int a = ops[i][0];
        int b = ops[i][1];

        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < b; k++)
            {
                res[j][k]++;
                maxi = max(res[j][k], maxi);
            }
        }
    }
    int count = 0;
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << res[j][k] << " ";
            if (maxi == res[j][k])
            {
                count += 1;
            }
        }
        cout << "\n";
    }
    return count;
}
int main()
{
    vector<vector<int>> ops = {{2, 2}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {3, 3}, {3, 3}, {3, 3}};
    cout << maxCount(3, 3, ops);
    return 0;
}