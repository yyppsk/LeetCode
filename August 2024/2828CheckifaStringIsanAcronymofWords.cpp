#include <bits/bits-stdc++.h>
using namespace std;
bool isAcronym(vector<string> &words, string s)
{
    string build;
    for (const auto &ch : words)
    {
        build.push_back(ch[0]);
    }

    return build == s;
}
int main()
{
    return 0;
}