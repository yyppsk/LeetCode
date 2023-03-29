#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int solve(long number)
{
    if (number == 0)
    {
        return number;
    }

    int count = 0;
    while (number != 0)
    {
        number &= (number - 1);
        count++;
    }
    return count;
}
int main()
{
    long n = 1110000111;
    cout << solve(n) << endl;
    return 0;
}