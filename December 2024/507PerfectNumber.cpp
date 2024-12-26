#include <bits/bits-stdc++.h>
using namespace std;

// Naive
bool checkPerfectNumber(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    if (sum == num)
        return true;
    return false;
}
int main()
{
    return 0;
}