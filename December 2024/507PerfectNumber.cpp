#include <bits/bits-stdc++.h>
using namespace std;

// Naive
bool checkPerfectNumber_NAIVE(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
        if (sum > num)
        {
            return false;
        }
    }

    if (sum == num)
        return true;
    return false;
}

// Better

bool checkPerfectNumber_better(int num)
{
    if (num < 0)
    {
        return false;
    }
    int sum = 0;
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if ((num / i) != num)
            {
                sum += (num / i);
            }
        }
    }
    return sum == num;
}

// optimal Euler method

long long pn(int p) { return (1LL << (p - 1)) * ((1LL << p) - 1); }

bool checkPerfectNumber(int num)
{
    int primes[] = {2, 3, 5, 7, 13, 17, 19, 31};

    for (int prime : primes)
    {
        if (pn(prime) == num)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}