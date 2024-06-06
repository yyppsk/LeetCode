#include <bits/bits-stdc++.h>
using namespace std;
vector<string> commonChars(vector<string> words)
{
    unordered_map<char, int> mp;
    vector<string> result;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        mp[ch] = INT_MAX;
    }

    for (int i = 0; i < words.size(); i++)
    {
        vector<int> frequency(26, 0);

        for (int j = 0; j < words[i].size(); j++)
        {
            frequency[words[i][j] - 'a']++;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            mp[ch] = min(mp[ch], frequency[ch - 'a']);
        }
    }

    for (auto &ele : mp)
    {
        for (int i = 0; i < ele.second; i++)
        {
            result.push_back(string(1, ele.first));
        }
    }

    return result;
}

int main()
{
    commonChars({"bella", "label", "roller"});
    return 0;
}