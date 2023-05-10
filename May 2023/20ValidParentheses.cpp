#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(')
            st.push(')');
        else if (c == '{')
            st.push('}');
        else if (c == '[')
            st.push(']');
        else if (st.empty() || st.top() != c)
        {
            return false;
        }
        else
            st.pop();
    }
    return st.empty();
}
int main()
{
    string s = "()[]{}";
    cout << isValid(s);
    return 0;
}