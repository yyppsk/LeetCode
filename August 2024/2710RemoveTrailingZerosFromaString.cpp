#include <bits/bits-stdc++.h>
using namespace std;
string removeTrailingZeros(string num)
{
    while (num.length() > 0)
    {
        if (num.back() == '0')
        {
            num.pop_back();
        }
        else
            return num;
    }
    return num;
}
int main()
{
    return 0;
}