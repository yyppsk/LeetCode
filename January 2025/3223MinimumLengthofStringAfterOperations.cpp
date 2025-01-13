#include <bits/bits-stdc++.h>
using namespace std;
int minimumLength(string s)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]] += 1;
    }

    int answer = 0;

    for (auto &ele : freq)
    {
        while (ele.second > 2)
        {
            ele.second -= 2;
        }
    }

    for (auto &ele : freq)
    {
        answer += ele.second;
        cout << ele.first << ":" << ele.second << "\n";
    }

    return answer;
}
int main()
{
    string s = "abaacbcbb";
    minimumLength(s);
    return 0;
}