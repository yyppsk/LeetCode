#include <bits/bits-stdc++.h>
using namespace std;
// brute force
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> result;
    unordered_set<string> already;
    for (int i = 0; i < words1.size(); i++)
    {
        if (already.find(words1[i]) != already.end())
            continue;

        bool isSubset = true;
        for (int j = 0; j < words2.size(); j++)
        {
            vector<int> freq1(26, 0), freq2(26, 0);

            for (char c : words1[i])
                freq1[c - 'a']++;

            for (char c : words2[j])
                freq2[c - 'a']++;

            for (int k = 0; k < 26; k++)
            {
                if (freq2[k] > freq1[k])
                {
                    isSubset = false;
                    break;
                }
            }

            if (!isSubset)
                break;
        }

        already.insert(words1[i]);
        if (isSubset)
            result.emplace_back(words1[i]);
    }

    return result;
}

// Optimal
vector<int> counter(string &word)
{
    vector<int> count(26);
    for (char c : word)
        count[c - 'a']++;
    return count;
}

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<int> count(26), temporaryFreq(26);
    int i;
    for (string &b : words2)
    {
        temporaryFreq = counter(b);
        for (i = 0; i < 26; ++i)
            count[i] = max(count[i], temporaryFreq[i]);
    }
    vector<string> res;
    for (string &a : words1)
    {
        temporaryFreq = counter(a);
        for (i = 0; i < 26; ++i)
            if (temporaryFreq[i] < count[i])
                break;
        if (i == 26)
            res.push_back(a);
    }
    return res;
}

int main()
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"}, words2 = {"l", "e"};

    wordSubsets(words1, words2);

    return 0;
}