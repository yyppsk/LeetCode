#include <bits/bits-stdc++.h>
using namespace std;
int getLucky(string s, int k)
{
    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int digit = s[i] - 'a' + 1;
        if (digit >= 10)
        {
            sum += digit % 10;
            sum += digit / 10;
        }
        else
            sum += digit;
    }

    k--;

    int number = sum;
    while (k)
    {
        int sum = 0;
        while (number > 0)
        {
            int digit = number % 10;
            number = number / 10;
            sum += digit;
        }

        number = sum;
        k--;
    }
    return number;
}
int main()
{
    getLucky("leetcode", 2);
    return 0;
}