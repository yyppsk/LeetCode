#include <bits/bits-stdc++.h>
using namespace std;
int minimumPushes(string word)
{
    int size = word.size();
    int keypadRow = 1;
    int rounds = size / 8;
    int remainingKeys = size % 8;

    int totalKeyPress = 0;
    while (rounds--)
    {
        totalKeyPress += 8 * keypadRow;
        keypadRow += 1;
    }

    return (totalKeyPress + remainingKeys);
}

int main()
{
    return 0;
}