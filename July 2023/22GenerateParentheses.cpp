#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findStuff(vector<string> &result, int n, int open, int close, string &output)
{
    if (open == 0 && close == 0)
    {
        result.push_back(output);
        return;
    }
    // add karna hai jab open bracket > 0
    if (open > 0)
    {
        output.push_back('(');
        findStuff(result, n, open - 1, close, output);
        output.pop_back();
    }
    // add nahi karna hai close < open
    if (open < close)
    {
        output.push_back(')');
        findStuff(result, n, open, close - 1, output);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    int open = n;
    int close = n;
    string output = "";
    findStuff(result, n, open, close, output);
    return result;
}
int main()
{
    return 0;
}