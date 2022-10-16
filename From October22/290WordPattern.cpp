#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> mapp;
    string str = "";
    vector<string> res;
    s.push_back(' ');
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        str += s[i];
        if (s[i] == ' ')
        {
            mapp[pattern[j]] = str;
            res.push_back(str);
            str = "";
        }
    }
    for (auto i : res)
    {
        cout << i << " " << endl;
    }
    for (auto i : mapp)
    {
        cout << i.first << " : " << i.second << endl;
    }
    return 0;
}
int main()
{
    string pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s);
    return 0;
}