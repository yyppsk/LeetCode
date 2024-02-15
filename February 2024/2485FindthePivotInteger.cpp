#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pivotInteger2(int n)
    {
        int answer = (n * n + n) / 2;
        int root = sqrt(answer);
        if (root * root == answer)
            return root;
        else
            return -1;
    }

    // Binary Search on Answer
    int pivotInteger(int n)
    {
        int l = 1, r = n, sum = n * (n + 1) / 2;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (m * m - sum < 0)
                l = m + 1;
            else
                r = m;
        }
        return l * l - sum == 0 ? l : -1;
    }
};
int main()
{
    return 0;
}