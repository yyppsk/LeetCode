#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int smallestEvenMultiple(int n)
{
    int possible = 2;
    int looper = n;
    while (true)
    {
        possible = looper;
        int divfive = looper;
        if (((possible & 1) == 0) && ((divfive % n) == 0))
        {
            return possible;
        }
        looper++;
    }
    return 0;
}
int main()
{
    return 0;
}