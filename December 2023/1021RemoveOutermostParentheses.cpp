#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int maxDepth(string s)
{
    // stack<int> st;
    int current = 0;
    int DepthMax = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            current++;
        }
        else if (s[i] == ')')
        {
            DepthMax = max(DepthMax, current);
            current--;
        }
    }
    return DepthMax;
}
int main()
{
    string s = "(1)+((2))+(((3)))";
    cout << maxDepth(s);
    return 0;
}