#include <bits/bits-stdc++.h>
using namespace std;
bool check(int &number)
{
    int copy = number;
    while (copy > 0)
    {
        int digit = copy % 10;
        copy /= 10;
        if (digit == 0)
        {
            return false;
        }

        if (number % digit != 0)
        {
            return false;
        }
    }

    return true;
}
vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;
    for (int number = left; number <= right; number++)
    {
        if (check(number))
        {
            result.push_back(number);
        }
    }

    return result;
}
int main()
{
    return 0;
}