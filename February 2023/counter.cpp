#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve()
{
}
int main()
{
    string s = "this is great thanks very much";
    int count = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            count++;
    }
    cout << count;
    return 0;
}