#include <bits/bits-stdc++.h>
using namespace std;
int prefixCount(vector<string> &words, string pref)
{
    int prefSize = pref.length();
    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].substr(0, prefSize) == pref)
            cnt += 1;
    }
    return cnt;
}
int main()
{
    vector<string> words = {"pay", "attention", "practice", "attend"};
    string pref = "at";
    prefixCount(words, pref);
    return 0;
}