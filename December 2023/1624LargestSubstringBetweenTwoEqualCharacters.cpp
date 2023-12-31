#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int maxLengthBetweenEqualCharacters(string s)
{
    unordered_map<char, pair<int, int>> mp;
    int low = 0, high = s.size() - 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        mp[i] = {-1, -1};
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]].first == -1)
        {
            // firse occur
            mp[s[i]].first = i;
        }
        else
        {
            mp[s[i]].second = i;
        }
    }
    int maxi = INT_MIN;
    for (auto ele : mp)
    {
        cout << ele.first << ":"
             << "{" << ele.second.first << ":" << ele.second.second << "}" << endl;

        maxi = max(maxi, ((ele.second.second - 1) - ele.second.first));
    }
    return maxi;
}
int main()
{
    cout << maxLengthBetweenEqualCharacters("aa");
    return 0;
}