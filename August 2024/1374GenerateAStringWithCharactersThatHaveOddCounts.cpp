#include <bits/bits-stdc++.h>
using namespace std;
string generateTheString(int n)
{
    if (n == 1)
    {
        return "a";
    }
    string result = "";
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            result.push_back('a');
        }

        result.push_back('b');
    }
    else
    {
        int steps = n - 2;
        while (steps--)
        {
            result.push_back('a');
        }
        result.push_back('b');
        result.push_back('c');
    }

    return result;
}
int main()
{
    return 0;
}