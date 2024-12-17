#include <bits/stdc++.h>
using namespace std;

/*

Adding only one character serves two purposes:

Break the repetition streak — It prevents exceeding the repeatLimit constraint.
Preserve lexicographical order — It allows you to re-add the "highest priority" character (currentChar) as soon as the streak is broken.
Why Not Add All a Characters?
If you add all available 'a' characters when breaking the streak, you lose the ability to go back to the lexicographically larger character (z or c) that was temporarily skipped. For example:

Wrong choice: "zzcccaaaca"
Here, after adding all 'a', you can no longer go back and add z or c in a meaningful way without violating the order.

Correct choice: "zzcccacaaa"
By adding only one 'a', you break the streak, allowing the algorithm to return to 'c' (or 'z' if available) and maintain the largest lexicographical order.

*/
string repeatLimitedString(string s, int repeatLimit)
{
    string result = "";
    map<char, int, greater<char>> freq;

    for (const char &ele : s)
    {
        freq[ele]++;
    }

    while (!freq.empty())
    {
        auto it = freq.begin();
        char currentChar = it->first;
        int currentCount = it->second;

        if (!result.empty() && result.back() == currentChar)
        {

            auto nextIt = next(it);
            if (nextIt == freq.end())
                break;

            char nextChar = nextIt->first;
            int count = nextIt->second;
            int addCount = min(count, repeatLimit);

            for (int i = 0; i < addCount; i++)
            {
                result.push_back(nextChar);
            }
            freq[nextChar] -= addCount;

            if (nextIt->second == 0)
                freq.erase(nextIt);
        }
        else
        {

            int addCount = min(currentCount, repeatLimit);
            for (int i = 0; i < addCount; i++)
            {
                result.push_back(currentChar);
            }
            freq[currentChar] -= addCount;

            if (freq[currentChar] == 0)
                freq.erase(currentChar);
        }
    }

    return result;
}

int main()
{
    string s = "cczaaaazcc";
    int repeatLimit = 3;
    cout << repeatLimitedString(s, repeatLimit) << endl;
    return 0;
}
