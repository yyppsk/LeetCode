#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
void solve()
{
}
int main()
{
    string s = "abbaca";
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())

            st.push(s[i]);
        else if (st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
/*
 int i = 0;
        for(int j = 1; j < s.size(); ++j)
            if (i < 0 || s[i] != s[j]) s[++i] = s[j];
            else --i;
        return s.substr(0, i + 1);*/