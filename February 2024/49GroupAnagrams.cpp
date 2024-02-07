#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ret;
        for (const auto &s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        ret.reserve(map.size());
        for (auto &p : map)
        {
            ret.push_back(std::move(p.second));
        }
        return ret;
    }
};
int main()
{
    return 0;
}