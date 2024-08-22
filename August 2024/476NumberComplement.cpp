#include <bits/bits-stdc++.h>

using namespace std;

int findComplement(int num)
{
    vector<int> bits;
    int result = 0;
    int copy = num;
    while (copy > 0)
    {
        bits.push_back(copy & 1);
        copy = copy >> 1;
    }

    for (int i = bits.size() - 1; i >= 0; i--)
    {
        if (bits[i] == 1)
        {
            result |= 0;
        }
        else
        {
            result |= 1;
        }
        result = result << 1;
    }

    result = result >> 1;

    return result;
}

int main()
{
    cout << findComplement(5);
    return 0;
}