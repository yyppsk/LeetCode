#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isBadVersion(int version)
{
    int bad = 5;
    if (version >= bad)
    {
        return true;
    }
    return false;
}
int firstBadVersion(int n)
{
    int start = 1, end = n;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (!isBadVersion(mid))
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}
int main()
{
    int n = 10;
    int bad = 5;
    cout << firstBadVersion(n);
    return 0;
}