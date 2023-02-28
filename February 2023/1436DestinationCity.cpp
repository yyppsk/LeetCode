#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
string destCity(vector<vector<string>> &paths)
{
    unordered_map<string, string> mp;
    for (auto i : paths)
        for (auto j : i)
        {
            mp.insert({i[0], i[1]});
        }
    for (int i = 0; i < paths.size(); i++)
        for (int j = 0; j < paths[i].size(); j++)
        {
            if (mp.find(paths[i][j]) == mp.end())
                return paths[i][j];
        }

    return "Null";
}
int main()
{
    vector<vector<string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    cout << destCity(paths) << endl;
    return 0;
}