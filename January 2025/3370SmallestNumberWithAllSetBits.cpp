#include <bits/bits-stdc++.h>
using namespace std;
int smallestNumber(int n)
{
    int res = 1023;
    int last = 1023;
    while (res >= n)
    {
        last = res;
        res = res >> 1;
    }

    return last;
}
int main()
{
    cout << smallestNumber(5);
    return 0;
}