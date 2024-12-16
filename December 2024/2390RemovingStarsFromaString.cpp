#include <bits/bits-stdc++.h>
using namespace std;

// constant space

string removeStars(string s)
{
    int index = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '*')
            --index;
        else
            s[index++] = s[i];
    }
    s.resize(index);
    return s;
}

// stack
string removeStars_stack(string s)
{
    string sol;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
            st.pop();
        else
            st.push(s[i]);
    }

    while (!st.empty())
    {
        sol.push_back(st.top());
        st.pop();
    }
    reverse(sol.begin(), sol.end());
    return sol;
}

string removeStars_nonstack(string s)
{
    string sol;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '*')
        {
            sol.push_back(s[i]);
        }
        else
        {
            sol.pop_back();
        }
    }

    return sol;
}
int main()
{
    string s = "leet**cod*e";
    cout << removeStars(s);
    return 0;
}