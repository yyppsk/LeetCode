#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isThree2(int n)
{
    // I can try modulo first
    int count = 0, div = 1;
    while (div <= n)
    {
        if ((n % div++) == 0)
        {
            ++count;
        }
        if (count > 3)
            return false;
    }
    if (count == 3)
        return true;
    return false;
}
bool isThree(int n)
{
    // No mudulo stuff
    int d = 2;
    for (int i = 2; i < n && d <= 3; i += 1)
        d += n % i == 0;
    return d == 3;
}
int main()
{
    return 0;
}