#include <bits/bits-stdc++.h>
using namespace std;

// 1 Fail
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    unordered_map<char, int> pattMap;
    int size = pattern.size();
    for (int i = 0; i < pattern.size(); i++)
    {
        pattMap[pattern[i]] += 1;
    }

    int i = 0;
    vector<string> answer;

    for (auto &ele : pattMap)
    {
        cout << ele.first << ":" << ele.second << "\n";
    }

    for (int j = 0; j < words.size(); j++)
    {
        unordered_map<char, int> fqMap;

        cout << words[j] << ": On Line \n";

        for (int i = 0; i < size; i++)
        {
            fqMap[words[j][i]] += 1;
        }

        for (auto &ele : fqMap)
        {
            cout << ele.first << ":" << ele.second << "\n";
        }

        int i = 0;
        bool isValid = true;
        while (i < size)
        {
            if (pattMap[pattern[i]] == fqMap[words[j][i]])
            {
                i += pattMap[pattern[i]];
            }
            else
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            answer.push_back(words[j]);
        }
    }

    return answer;
}

class Solution
{
public:
    void normalise(string &str)
    {
        char start = 'a';
        unordered_map<char, char> mapping;

        for (int i = 0; i < str.length(); i++)
        {
            if (mapping.find(str[i]) == mapping.end())
            {
                mapping[str[i]] = start;
                start++;
            }
        }
        for (int i = 0; i < str.length(); i++)
        {
            char mappedcharacter = mapping[str[i]];
            str[i] = mappedcharacter;
        }
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        normalise(pattern);
        for (int i = 0; i < words.size(); i++)
        {
            string currWord = words[i];

            string currWordCopy = currWord;
            normalise(currWordCopy);
            if (currWordCopy.compare(pattern) == 0)
            {
                ans.push_back(currWord);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> words = {"abc",
                            "deq",
                            "mee",
                            "aqq",
                            "dkd",
                            "ccc"};

    string pattern = "abb";

    findAndReplacePattern(words, pattern);
    return 0;
}