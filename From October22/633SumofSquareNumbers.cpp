#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool judgeSquareSum(int c)
{
    for (long int i = 0; (i*i) <= c; i++)
    {
        long int start = 0, end = c;
        long int target = i * i;
        while (start <= end)
        {
            long int mid = start + (end - start) / 2;
            long int temp = mid * mid;
            if (((temp) + target) == c)
                return true;
            if ((temp) + target < c)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return false;
}
int main()
{
    int c = 18;
    cout << judgeSquareSum(c);
    return 0;
}