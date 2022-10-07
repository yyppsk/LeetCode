#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    string s = "";
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = 0; j < strs[i].size(); j++)
        {
            if (strs[i][j] == strs[i + 1][j])
                s += strs[i][j];
            cout << strs[i][j] << " ";
        }
        cout << endl;
    }
    return s;
}
int main()
{
    vector<string> arr = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(arr);
    return 0;
}