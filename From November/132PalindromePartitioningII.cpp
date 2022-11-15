#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int minCut(string s)
{
}
bool ispal(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (s == temp)
        return true;
    else
        return false;
}
void solve(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if(ispal()
}
int main()
{
    string s = "aab";
    cout << ispal(s);
    return 0;
}