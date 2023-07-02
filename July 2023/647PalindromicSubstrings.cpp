#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int track(string s, int i, int j)
{
    int cnt = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        cnt++, i--, j++;
    }
    return cnt;
}
int countSubstrings(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // Track even stuff
        int evenStuff = track(s, i, i + 1);
        count = count + evenStuff;
        // Track odd stuff
        int oddStuff = track(s, i, i);
        count = count + oddStuff;
    }
    return count;
}
int main()
{
    return 0;
}