#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
bool isvowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
}
int maxVowels(string s, int k)
{
    //Kadane & Sliding Window
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
    //Queue
    deque<int> dq;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        count += isvowel(s[i]);
        dq.push_back(s[i]);
    }
    int maxcount = count;
    for (int i = k; i < s.size(); i++)
    {
        dq.push_back(s[i]);
        count += isvowel(dq.back());
        count -= isvowel(dq.front());
        dq.pop_front();
        maxcount = max(maxcount, count);
    }
    return maxcount;
}
int main()
{
    string s = "ieetcode";
    int k = 3;
    cout << maxVowels(s, k);
    return 0;
}