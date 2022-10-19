#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> shortestToChar(string s, char c)
{
    vector<int> ans;
    int start = 0, end = 1;
    while (end < s.size())
    {
        cout << "Check " << s[start] << " : " << s[end] << endl;
        if (s[end] == c)
        {
            int dist = abs(end - start);
            int k = 0;
            int res = dist;
            while (k <= dist)
            {
                ans.push_back(abs(end - start));
                start++;
                k++;
            }
        }
        end++;
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return {};
}
int main()
{
    string str = "loveleetcode";
    char c = 'e';
    shortestToChar(str, c);
    return 0;
}