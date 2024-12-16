#include <bits/bits-stdc++.h>
using namespace std;

string clearDigits(string s)
{
    int index = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            --index;
        else
            s[index++] = s[i];
    }
    s.resize(index);
    return s;
}

// stack
string clearDigits_stack(string s)
{
    string sol;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
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
int main()
{
    return 0;
}