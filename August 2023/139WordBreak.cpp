#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<bool>> memo;

bool recurDp(string s, vector<string> &wordDict, int idx, string &build)
{
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true; // Base case: An empty string can be formed
    for (int i = 1; i <= s.size(); i++)
    {
        for (const string &word : wordDict)
        {
            int wordLen = word.length();
            if (i >= wordLen && dp[i - wordLen] && s.substr(i - wordLen, wordLen) == word)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
bool recur(string s, vector<string> &wordDict, int idx, string &build)
{
    // Base case
    if (idx == s.length() && s == build)
    {
        std::cout << build << std::endl;
        return true;
    }
    if (memo[idx][build.length()])
        return false; // already computed so return
    // "Take" part
    for (const std::string &word : wordDict)
    {
        if (s.substr(idx, word.length()) == word)
        {
            // Save the current state of build to restore it later
            std::string previousBuild = build;

            // Append the word from wordDict
            build += word;

            // Recur with the updated build and the next index
            bool found = recur(s, wordDict, idx + word.length(), build);

            // Restore build to its previous state (remove the added word)
            build = previousBuild;

            // If the match was found in the subsequent recursion, return true
            if (found)
                return true;
        }
    }

    // If the function reaches this point, it means the current branch doesn't lead to a valid solution
    memo[idx][build.length()] = true; // for this index 0, upto 5 assuming it's found and it did not give a soln
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    // Brute force approach right now suggests that I should try to find my possible answer with in the string s with word
    // Dict

    // take and not take pattern maybe?
    string build = "";

    memo.assign(s.length() + 1, vector<bool>(s.length() + 1, false));

    return recurDp(s, wordDict, 0, build);
}
int main()
{
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << (wordBreak(s, wordDict) ? "True" : "False");
    cout << endl;
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << (wordBreak(s, wordDict) ? "True" : "False");
    return 0;
}