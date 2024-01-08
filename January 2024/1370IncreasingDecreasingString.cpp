#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
string sortString(string s)
{
    string result = "";
    map<char, int> mp;

    for (auto &ch : s)
    {
        mp[ch]++;
    }

    while (result.size() < s.size())
    {
        // Loop for ascending order
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second > 0)
            {
                result.push_back(it->first);
                it->second--;
            }
        }

        // Loop for descending order
        for (auto it = mp.rbegin(); it != mp.rend(); ++it)
        {
            if (it->second > 0)
            {
                result.push_back(it->first);
                it->second--;
            }
        }
    }

    return result;
}
string sortStringBruteSolution(string s)
{
    string result = "";
    map<char, int> mp;
    for (auto &ch : s)
    {
        mp[ch]++;
    }

    // Repeat the steps from 1 to 6 until you pick all characters from s.
    // Pick the smallest character from s and append it to the result.
    while (result.size() < s.size())
    {
        if (mp.begin()->second > 0)
        {
            result.push_back(mp.begin()->first);
            mp.begin()->second--;
        }
        else
        {
            mp.erase(mp.begin()->first);
        }

        // Pick the smallest character from s which is greater than the last appended character to the result and append it.
        for (auto &ele : mp)
        {
            // Repeat step 2 until you cannot pick more characters.
            while (ele.first > result.back() && ele.second > 0)
            {
                result.push_back(ele.first);
            }
        }
        // Pick the largest character from s and append it to the result.
        if (mp.rbegin()->second > 0)
        {
            result.push_back(mp.rbegin()->first);
            mp.rbegin()->second--;
        }
        else
        {
            mp.erase(mp.rbegin()->first);
        }
        // Pick the largest character from s which is smaller than the last appended character to the result and append it.
        for (auto it = mp.rbegin(); it != mp.rend(); ++it)
        {
            auto &ele = *it;

            // Repeat step until you cannot pick more characters
            while (!result.empty() && ele.first < result.back() && ele.second > 0)
            {
                result.push_back(ele.first);
                ele.second--;
            }
        }
    }
    // for (auto &ch : mp)
    // {
    //     cout << ch.first << ":" << ch.second << "\n";
    // }

    return result;
}
int main()
{
    cout << sortString("aaaabbbbcccc") << endl;
    cout << "abccbaabccba";
    return 0;
}