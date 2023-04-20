#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    /*
    int counter = 0;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (g[i] <= s[j] && (s[j] >= 0 && g[i] >= 0))
            {
                counter++;
                s[j] = -1;
                g[i] = -1;
            }
        }
    }
    for (auto i : s)
    {
        cout << i << " ";
    }
    return counter;
    */
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int n = g.size();
    int ind = 0, cnt = 0;
    for (int i = 0; i < n && ind < s.size(); i++)
    {
        if (s[ind] >= g[i])
        {
            ind++, cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> g = {2, 5, 6, 1, 2, 4, 6, 1, 3, 6, 8, 4, 2, 1, 1}, s = {5, 2, 1, 2, 4, 2, 1, 2, 4};
    cout << findContentChildren(g, s);
    return 0;
}