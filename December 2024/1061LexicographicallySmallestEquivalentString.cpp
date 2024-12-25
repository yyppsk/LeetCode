#include <bits/bits-stdc++.h>
using namespace std;

// complete brute idea
string smallestEquivalentString(string s1, string s2, string baseStr)
{

    std::unordered_map<char, std::set<char>> relation;

    for (size_t i = 0; i < s1.size(); i++)
    {
        char a = s1[i];
        char b = s2[i];

        if (relation.find(a) == relation.end())
            relation[a] = {a};
        if (relation.find(b) == relation.end())
            relation[b] = {b};

        // Merge equivalence sets
        std::set<char> combined = relation[a];
        combined.insert(relation[b].begin(), relation[b].end());

        // Update equivalence sets for all involved characters
        for (char c : combined)
        {
            relation[c] = combined;
        }
    }

    for (int i = 0; i < baseStr.length(); i++)
    {
        if (relation.find(baseStr[i]) != relation.end())
            baseStr[i] = *relation[baseStr[i]].begin();
    }

    return baseStr;
}
int main()
{
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout << smallestEquivalentString(s1, s2, baseStr);

    return 0;
}