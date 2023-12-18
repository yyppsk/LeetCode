#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
string removeOuterParentheses(string s)
{
    int count = 0;
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && count == 0)
        {
            count++;
        }
        else if (s[i] == '(' && count > 1)
        {
            count++;
            result += s[i];
        }
        else if (s[i] == ')' && count == 1)
        {
            count--;
        }
        else if (s[i] == ')' && count > 1)
        {
            result += s[i];
            count--;
        }
    }
    return result;
}
int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s);
    return 0;
}