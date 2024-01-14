#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

bool closeStrings_Optimized(string word1, string word2)
{
    if (word1.size() != word2.size())
    {
        return false;
    }

    unordered_map<char, int> freqWord1, freqWord2, freqCount1, freqCount2;
    unordered_set<char> charSet1, charSet2;

    for (char c : word1)
    {
        freqWord1[c]++;
        charSet1.insert(c);
    }

    for (char c : word2)
    {
        freqWord2[c]++;
        charSet2.insert(c);
    }

    for (const auto &pair : freqWord1)
    {
        freqCount1[pair.second]++;
    }

    for (const auto &pair : freqWord2)
    {
        freqCount2[pair.second]++;
    }

    return charSet1 == charSet2 && freqCount1 == freqCount2;
}

bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
    {
        return false;
    }

    unordered_map<char, int> freqWord1, freqWord2;
    for (char c : word1)
    {
        freqWord1[c]++;
    }

    for (char c : word2)
    {
        freqWord2[c]++;
    }

    unordered_set<int> freqSet1, freqSet2;
    unordered_set<char> charSet1, charSet2;

    for (const auto &pair : freqWord1)
    {
        freqSet1.insert(pair.second);
        charSet1.insert(pair.first);
    }

    for (const auto &pair : freqWord2)
    {
        freqSet2.insert(pair.second);
        charSet2.insert(pair.first);
    }

    return freqSet1 == freqSet2 && charSet1 == charSet2 && isInterchangeable(freqWord1, freqWord2);
}

bool isInterchangeable(const unordered_map<char, int> &freqWord1, const unordered_map<char, int> &freqWord2)
{
    unordered_map<int, int> freqCount1, freqCount2;

    for (const auto &pair : freqWord1)
    {
        freqCount1[pair.second]++;
    }

    for (const auto &pair : freqWord2)
    {
        freqCount2[pair.second]++;
    }

    return freqCount1 == freqCount2;
}
int main()
{
    cout << endl;
    cout << closeStrings("abbzzca",
                         "babzzcz");
    return 0;
}