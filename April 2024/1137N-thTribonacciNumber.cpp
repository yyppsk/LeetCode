#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int arr[38];
    int find(int n)
    {
        if (n == 0)
            return arr[n] = 0;
        if (n == 1 || n == 2)
            return arr[n] = 1;
        if (arr[n] != -1)
            return arr[n];
        return arr[n] =
                   find(n - 1) + find(n - 2) + find(n - 3);
    }
    int tribonacci(int n)
    {
        memset(arr, -1, sizeof(arr));
        return find(n);
    }
};
int main()
{
    return 0;
}