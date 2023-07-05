#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int countPrimes(int n)
{
    if (n == 0)
        return 0;
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            ans++;
            int j = 2 * i;
            while (j < n)
            {
                primes[j] = false;
                j += i;
            }
        }
    }
    return ans;
}
int main()
{
    cout << countPrimes(10);
    return 0;
}