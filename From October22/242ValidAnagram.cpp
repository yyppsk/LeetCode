#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }
    unordered_map<char, int> map2;
    for (int i = 0; i < s.size(); i++)
    {
        map2[t[i]]++;
    }
    /*
    for (auto i : map)
    {
        cout << i.first << ":" << i.second << endl;
    }
    for (auto i : map2)
    {
        cout << i.first << ":" << i.second << endl;
    }
    */
    for (auto ch : s)
    {
        if (map[ch] != map2[ch])
            return false;
    }
    return true;
}
int main()
{
    cout << isAnagram("WilliamShakespeare", "Iamaweakishspeller");
    return 0;
}