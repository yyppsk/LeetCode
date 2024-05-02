#include <bits/stdc++.h>
using namespace std;
long long wonderfulSubstrings(string word)
{
    int beautiful = 0;
    for (int i = 0; i < word.size(); i++)
    {
        for (int j = i; j < word.size(); j++)
        {
            unordered_map<char, int> mp;

            for (int k = i; k <= j; k++)
            {
                cout << word[k];
                mp[word[k]]++;
            }

            // cout << "\n\n";

            // for (auto &ele : mp)
            // {
            //     cout << ele.first << ":" << ele.second << "\n";
            // }

            int threshold = 0;

            for (char ch = 'a'; ch <= 'j'; ch++)
            {

                if (mp[ch] % 2 != 0)
                {
                    // cout << "Checking " << ch << ":" << mp[ch] << "\n";
                    threshold++;
                }

                if (threshold > 1)
                {
                    break;
                }
            }
            // cout << "Thresh : " << threshold << endl;

            if (threshold <= 1)
            {
                beautiful++;
            }
        }
    }
    return beautiful;
}
int main()
{
    cout << wonderfulSubstrings("aabc");
    return 0;
}