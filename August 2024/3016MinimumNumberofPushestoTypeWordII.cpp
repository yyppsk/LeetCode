#include <bits/bits-stdc++.h>
using namespace std;
int minimumPushes(string word)
{
    unordered_map<char, int> frequency;

    for (int i = 0; i < word.size(); i++)
    {
        frequency[word[i]]++;
    }

    priority_queue<int> topPriority;

    for (const auto &ele : frequency)
    {
        topPriority.push(ele.second);
    }

    int keyPress = 0, keyPosition = 0;

    while (!topPriority.empty())
    {
        keyPress += (keyPosition / 8 + 1) * topPriority.top();
        topPriority.pop();
        keyPosition += 1;
    }

    return keyPress;
}
int main()
{
    string s;
    char arr[11] = {'*', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= 10; j++)
        {
            s.push_back(arr[i]);
        }
    }
    // cout << s << "\n";
    cout << minimumPushes(s);
    return 0;
}