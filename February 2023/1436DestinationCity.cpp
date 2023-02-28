#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string destCity(vector<vector<string>> &paths)
{
    for (auto i : paths)
        for (auto j : i)
        {
            cout << j << endl;
        }
    return "Null";
}
int main()
{
    vector<vector<string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    cout << destCity(paths) << endl;
    return 0;
}