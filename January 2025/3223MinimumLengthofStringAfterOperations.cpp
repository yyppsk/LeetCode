#include <bits/bits-stdc++.h>
using namespace std;
int minimumLength(string s)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]] += 1;
    }

    int answer = 0;

    for (auto &ele : freq)
    {
        while (ele.second > 2)
        {
            ele.second -= 2;
        }
    }

    for (auto &ele : freq)
    {
        answer += ele.second;
        cout << ele.first << ":" << ele.second << "\n";
    }

    return answer;
}

// optimal for deletion

int minimumLength(string s)
{
    unordered_map<char, int> charFrequencyMap;

    for (char &ch : s)
    {
        charFrequencyMap[ch]++;
    }

    int deleteCount = 0;
    for (auto &pair : charFrequencyMap)
    {
        int frequency = pair.second;
        if (frequency % 2 == 1)
        {
            deleteCount += frequency - 1;
        }
        else
        {
            deleteCount += frequency - 2;
        }
    }

    return s.length() - deleteCount;
}
int main()
{
    string s = "abaacbcbb";
    minimumLength(s);
    return 0;
}