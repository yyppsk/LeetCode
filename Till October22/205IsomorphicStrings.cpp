#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
void solve()
{
}
int main()
{
    string s = "paper", t = "title";
    unordered_map<int, int> stotmap;
    unordered_map<int, int> ttosmap;
    for (int i = 0; i < s.size(); i++)
    {
        char c1 = s[i];
        char c2 = t[i];
        if (stotmap[c1] == 0 && ttosmap[c2] == 0)
        {
            stotmap[c1] = c2;
            ttosmap[c2] = c1;
        }
        else if (!((stotmap[c1] == c2) && (ttosmap[c2] == c)))
            return false;
    }

    return true;
}