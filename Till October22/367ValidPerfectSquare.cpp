#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isPerfectSquare(int num)
{
    long long start = 0;
    long long end = num;
    long long mid = start + (end - start) / 2;
    if (num == 1)
    {
        return true;
    }
    while (start <= end)
    {
        // cout << "Checking : " << mid * mid << endl;
        if (mid * mid == num)
            return mid;
        if (mid * mid > num)
        {
            end = mid - 1;
        }
        if (mid * mid < num)
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return false;
}
int main()
{
    int num = 9;
    for (int i = 0; i < 100; i++)
    {
        cout << "for " << i << " " << i << " " << isPerfectSquare(i * i) << endl;
    }
    return 0;
}