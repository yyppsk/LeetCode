#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
string solve(string s)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    for (auto i : freq)
    {
        cout << i << " " << endl;
    }

    return "";
}
int main()
{
    string s = "abcdbcced";
    cout << solve(s);
    return 0;
}