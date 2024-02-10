#include <bits/stdc++.h>
using namespace std;
class SolutionRecursive
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (checkPallindrome(s, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool checkPallindrome(string &s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }

        if (s[i] == s[j])
        {
            return checkPallindrome(s, i + 1, j - 1);
        }
        return false;
    }
};

class SolutionMemoization
{
public:
    int t[1001][1001];
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        memset(t, -1, sizeof(t));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (checkPallindrome(s, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool checkPallindrome(string &s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        if (s[i] == s[j])
        {
            return checkPallindrome(s, i + 1, j - 1);
        }
        return t[i][j] = false;
    }
};
// Bottom Up
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0;
        for (int substrLength = 1; substrLength <= n; substrLength++)
        {
            for (int i = 0; i + substrLength - 1 < n; i++)
            {
                int j = i + substrLength - 1;

                if (i == j)
                {
                    t[i][i] = true;
                }
                else if (i + 1 == j)
                {
                    t[i][j] = (s[i] == s[j]);
                }
                else
                {
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
                }
                if (t[i][j] == true)
                    count++;
            }
        }
        return count;
    }
};

// observation

class Solution
{
public:
    int count = 0;
    int countSubstrings(string s)
    {
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            check(s, i, i, n);
            check(s, i, i + 1, n);
        }
        return count;
    }

private:
    void check(string &s, int i, int j, int n)
    {
        while (i >= 0 && j < n && s[i++] == s[j++])
        {
            count++;
        }
    }
};
int main()
{
    return 0;
}