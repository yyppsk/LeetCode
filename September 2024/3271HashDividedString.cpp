#include <bits/bits-stdc++.h>
using namespace std;

string stringHash(string s, int k)
{
    string result;
    for (int i = 0; i < s.size(); i += k)
    {
        string subs = s.substr(i, k);
        int sum = 0;
        for (int j = 0; j < subs.size(); j++)
        {
            sum += (subs[j] - 'a');
        }

        int hashedChar = sum % 26;
        char ch = (hashedChar + 'a');
        result.push_back(ch);
    }
    return result;
}
int main()
{
    stringHash("abcd", 2);
    return 0;
}