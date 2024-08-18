#include <bits/bits-stdc++.h>
using namespace std;

bool solve(int num)
{
    for (int i = 2; i < 6 && num; i++)
        while (num % i == 0)
            num /= i;
    return num == 1;
}
int nthUglyNumber2(int n)
{
    int number = 1;
    while (n > 1)
    {
        if (solve(number))
        {
            n -= 1;
            if (n == 0)
            {
                return number;
            }
        }
        number += 1;
    }
    return number;
}

int nthUglyNumber(int n)
{
    set<long> set;
    long nthNumber = 1;
    set.insert(nthNumber);
    for (int i = 0; i < n; i++)
    {
        nthNumber = *set.begin();

        set.erase(nthNumber);

        set.insert(nthNumber * 2);
        set.insert(nthNumber * 3);
        set.insert(nthNumber * 5);
    }
    return nthNumber;
}

int main()
{
    cout << nthUglyNumber(10);
    return 0;
}