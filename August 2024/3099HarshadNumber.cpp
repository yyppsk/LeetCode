#include <bits/bits-stdc++.h>
using namespace std;
// An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.

int sumOfTheDigitsOfHarshadNumber(int x)
{
    auto digitSum = [](int x) -> int
    {
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    int sum = digitSum(x);

    return (x % sum == 0) ? sum : -1;
}
int main()
{
    return 0;
}