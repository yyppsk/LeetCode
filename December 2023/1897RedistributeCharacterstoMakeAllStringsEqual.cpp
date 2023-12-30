#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                mp[words[i][j]]++;
            }
        }

        int size = words.size();
        for (auto &ele : mp)
        {
            if (ele.second % size != 0)
                return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}