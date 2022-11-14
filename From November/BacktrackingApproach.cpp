#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve(string s, vector<string> &res, int init)
{
    if (s.size() == 0)
        return;
    if (s.size() == init)
        res.push_back(s);
    s.pop_back();
    solve(s, res, init);
    res.push_back(s);
}
int main()
{
    vector<string> res;
    string s = "aab";
    solve(s, res, s.size());
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}