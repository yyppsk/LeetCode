#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    // Recursion 62 Unique Path
    int recur(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
        {
            return 0;
        }

        int up = recur(i - 1, j);
        int left = recur(i, j - 1);
        return up + left;
    }
    int uniquePaths(int m, int n)
    {
        return recur(m - 1, n - 1);
    }
};
int main()
{
    return 0;
}