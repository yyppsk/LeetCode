#include <bits/bits-stdc++.h>
using namespace std;
int numOfStrings(vector<string> &patterns, string word)
{
    unordered_set<string> allSubstr;
    for (int i = 0; i < word.size(); i++)
    {

        for (int j = 0; j < word.size(); j++)
        {
            string s = "";
            for (int k = i; k <= j; k++)
            {
                s.push_back(word[k]);
            }
            allSubstr.insert(s);
        }
    }

    int count = 0;
    for (const auto &str : patterns)
    {
        if (allSubstr.find(str) != allSubstr.end())
        {
            count += 1;
        }
    }
    return count;
}
int main()
{
    vector<string> s;
    numOfStrings(s, "abc");
    return 0;
}