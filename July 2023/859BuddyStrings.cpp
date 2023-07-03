#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool buddyStrings(string s, string goal)
{
    int len = s.size();
    if (len != goal.size())
        return false;

    if (s == goal)
    {
        // Check if there are any repeated characters in s
        int freq[26] = {0};
        for (char ch : s)
        {
            if (++freq[ch - 'a'] > 1)
                return true;
        }
        return false;
    }

    int first = -1, second = -1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != goal[i])
        {
            if (first == -1)
                first = i;
            else if (second == -1)
                second = i;
            else
                return false; // More than two positions differ
        }
    }

    return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
}
bool buddyStrings2(string s, string goal)
{
    int len = s.size();
    if (len != goal.size())
        return false;

    int first = -1, second = -1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != goal[i])
        {
            if (first == -1)
                first = i;
            else if (second == -1)
                second = i;
            else
                return false; // More than two positions differ
        }
    }

    // Check if swapping characters at the found positions results in equal strings
    if (first != -1 && second != -1 && s[first] == goal[second] && s[second] == goal[first])
    {
        // Swap characters at the positions first and second in string s
        swap(s[first], s[second]);
        return s == goal;
    }

    // Special case where s and goal are already equal
    if (first == -1 && second == -1)
    {
        // Check if there are any repeated characters in s
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                    return true; // Swapping two instances of the same character will make s equal to goal
            }
        }
    }

    return false;
}
int main()
{
    buddyStrings("ab", "ab") ? cout << "true" : cout << "false";
    return 0;
}