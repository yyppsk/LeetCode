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
int main()
{
    return 0;
}