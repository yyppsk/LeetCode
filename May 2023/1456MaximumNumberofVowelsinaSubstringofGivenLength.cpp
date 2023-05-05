#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isvowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
}
int maxVowels(string s, int k)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        count += isvowel(s[i]);
    }
    cout << count << endl;
    int maxcount = count;
    for (int i = k; i < s.length(); i++)
    {
        count += isvowel(s[i]);
        count -= isvowel(s[i - k]);
        maxcount = max(maxcount, count);
    }
    return maxcount;
}
int main()
{
    string s = "leetcode";
    int k = 3;
    cout << maxVowels(s, k);
    return 0;
}