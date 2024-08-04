#include <bits/bits-stdc++.h>
using namespace std;

bool canAliceWin(vector<int> &nums)
{

    int total = accumulate(nums.begin(), nums.end(), 0);

    int aliceDouble =
        accumulate(nums.begin(), nums.end(), 0, [&](int sum, int num)
                   { return (num >= 10 && num < 100) ? sum + num : sum; });

    int aliceSingle =
        accumulate(nums.begin(), nums.end(), 0, [&](int sum, int num)
                   { return (num >= 0 && num < 10) ? sum + num : sum; });

    bool win = false;
    int bobSingle = total - aliceDouble;
    if (bobSingle >= aliceDouble)
    {
        win = false;
    }
    else
    {
        return true;
    }

    int bobDouble = total - aliceSingle;

    if (bobDouble >= aliceSingle)
    {
        win = false;
    }
    else
    {
        return true;
    }

    return win;
}

int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 14};
    cout << canAliceWin(num);
    return 0;
}