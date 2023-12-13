#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define mod 1000000007
class Solution
{
private:
    long long power(long long x, long long y)
    {
        if (y == 0)
            return 1;
        long long answer = power(x, y / 2);
        answer *= answer;
        answer %= mod;
        if (y % 2)
            answer *= x; // by the rule that for even power multiply by original
        answer %= mod;
        return answer;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long oddPositions = n / 2;
        long long evenPositions = n / 2 + n % 2;
        return (power(5, evenPositions) * power(4, oddPositions)) % mod;
    }
};
int main()
{
    return 0;
}