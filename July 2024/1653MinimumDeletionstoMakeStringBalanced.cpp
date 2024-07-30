#include <bits/bits-stdc++.h>
using namespace std;
int minimumDeletions(string s)
{
    int operations = 0;
    stack<char> history;
    history.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (!history.empty() && history.top() == 'a')
        {
            history.push(s[i]);
        }
        else if (s[i] == 'a')
        {
            if (!history.empty())
            {
                history.pop();
                operations++;
            }
        }
        else
        {
            history.push(s[i]);
        }
    }

    return operations;
}
int main()
{
    cout << minimumDeletions("bbaaaaabb");
    return 0;
}