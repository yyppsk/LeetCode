#include <bits/bits-stdc++.h>
using namespace std;

// BRUTE Force Accepted
bool doesValidArrayExist(vector<int> &derived)
{
    int n = derived.size();
    vector<int> og(n);
    og[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        og[i + 1] = derived[i] ^ og[i];
    }

    if (og.back() ^ og.front() == derived.back())
    {
        return true;
    }
    og[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        og[i + 1] = derived[i] ^ og[i];
    }

    if (og.back() ^ og.front() == derived.back())
    {
        return true;
    }

    return false;
}

// Observation
// D[0] = D[0]^[D1]
// D[1] = D[1]^[D2]
// D[2] = D[1]^[D0]
/*

D = [D[0]^[D1], D[1]^[D2], D[1]^[D0]];
So, D[0]^[D1]^D[1]^[D2]^D[1]^[D0] == 0 for being right

*/

bool doesValidArrayExist(vector<int> &derived)
{
    int xored = 0;
    for (int i = 0; i < derived.size() - 1; i++)
    {
        xored ^= derived[i] ^ derived[i + 1];
    }
    xored ^= (derived.back() ^ derived.front());
    return xored == 0;
}

// PARITY CHECK
bool doesValidArrayExist(vector<int> &derived)
{
    int sum = accumulate(derived.begin(), derived.end(), 0);
    return sum % 2 == 0;
}
int main()
{
    return 0;
}