#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<map<char, int>, vector<string>> mpp;
    for (string s : strs)
    {
        map<char, int> mpp2;
        for (char ch : s)
            mpp2[ch]++;
        mpp[mpp2].push_back(s);
    }
    for(Atu)
    vector<vector<string>> ans;
    for (auto x : mpp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    return 0;
}