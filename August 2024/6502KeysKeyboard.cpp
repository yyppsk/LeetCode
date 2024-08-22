#include <bits/bits-stdc++.h>
using namespace std;

int mini = INT_MAX;
int solve(int currentCopyLength, int currentScreenLength, int &n)
{
    if (currentScreenLength == 0)
        return 0;

    if (currentScreenLength >= n)
    {
        return mini;
    }
    printf("solve(%d,%d,%d)\n", currentCopyLength, currentCopyLength, n);
    int left = solve(currentCopyLength + currentScreenLength, currentCopyLength + currentScreenLength, n);
    printf("solve(%d,%d,%d)\n", currentCopyLength, currentCopyLength, n);
    int right = solve(currentCopyLength, currentCopyLength + currentScreenLength, n);

    return min(left, right);
}
int minSteps(int n)
{
    int currentCopyLength = 1;
    int currentScreenLength = 1;
    cout << solve(currentCopyLength, currentScreenLength, n);
}
int main()
{
    minSteps(6);
    return 0;
}