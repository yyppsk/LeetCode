#include <bits/bits-stdc++.h>
using namespace std;

class Solution2
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' || c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I';
    }

    string sortVowels(string s)
    {
        string temp;

        for (char c : s)
        {
            if (isVowel(c))
            {
                temp += c;
            }
        }

        sort(temp.begin(), temp.end());

        int j = 0;
        string ans;
        for (int i = 0; i < s.size(); i++)
        {

            if (isVowel(s[i]))
            {
                ans += temp[j];
                j++;
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};

string sortVowels(string s)
{
    vector<int> requiedIndexVowel;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> vowelPosition;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            requiedIndexVowel.push_back(i);
            vowelPosition.push({s[i], i});
        }
    }

    for (int i = 0; i < requiedIndexVowel.size(); i++)
    {
        s[requiedIndexVowel[i]] = vowelPosition.top().first;
        vowelPosition.pop();
    }

    return s;
}

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }

    return false;
}

string sortVowels3(string s)
{

    priority_queue<char, vector<char>, greater<char>> vowelPosition;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowelPosition.push(s[i]);
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]) && !vowelPosition.empty())
        {

            s[i] = vowelPosition.top();
            vowelPosition.pop();
        }
    }
    return s;
}
int main()
{
    string s = "lEetcOde";
    cout << (sortVowels3(s) == "lEOtcede") ? "Correct" : "Wrong";
    return 0;
}