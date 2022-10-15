#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int maxNumberOfBalloons(string text)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n')
            freq[text[i]]++;
    }
    if (freq.size() != 5)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (auto i : freq)
    {
        cout << i.first << " " << i.second << endl;
        if (i.second < mini)
        {
            mini = i.second;
        }
    }
    int minba;
    if (freq['a'] <= freq['b'] && freq['a'] <= freq['n'])
    {
        minba = freq['a'];
    }
    else if (freq['b'] <= freq['a'] && freq['b'] <= freq['n'])
    {
        minba = freq['b'];
    }
    else if (freq['n'] <= freq['a'] && freq['n'] <= freq['b'])
    {
        minba = freq['n'];
    }
    if ((freq['l'] >= 2) && (freq['o'] >= 2))
        return min(minba, min(freq['l'] / 2, freq['o'] / 2));
    else
        return 0;
}
int main()
{
    string str = "nlaebolko";
    // ek -> balloon
    cout << maxNumberOfBalloons(str);
    return 0;
}
