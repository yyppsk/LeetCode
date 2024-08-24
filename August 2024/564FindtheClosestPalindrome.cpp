#include <bits/bits-stdc++.h>
using namespace std;

class Solution_1TLE
{
public:
    bool checkerPallindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    string nearestPalindromic(string n)
    {
        unsigned long long ogNumber = stoull(n); // Convert string to unsigned long long
        unsigned long long left = ogNumber - 1;  // Start checking from the number just smaller than the original
        unsigned long long right = ogNumber + 1; // Start checking from the number just larger than the original

        while (true)
        {
            if (left >= 0 && checkerPallindrome(to_string(left)))
            {
                // If the left side palindrome is found
                return to_string(left);
            }

            if (right <= 999999999999999999ULL && checkerPallindrome(to_string(right)))
            {
                // If the right side palindrome is found
                return to_string(right);
            }

            // Decrement left and increment right for the next iteration
            left--;
            right++;
        }
    }
};

/*
    Time: O(1)
    Space: O(1)
    Tag: Maths, Strings, Implementation
    Difficulty: H
*/

class Solution
{

    bool is10__(string s)
    { // for 10* and 10*(0+1) types
        if (s[0] == '1')
        {
            for (int i = 1; i < s.length() - 1; i++)
            {
                if (s[i] != '0')
                    return false;
            }
            if (s.back() != '0' && s.back() != '1')
                return false;
            return true;
        }
        return false;
    }

    bool is99__(string s)
    { // for 99* types
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '9')
                return false;
        }
        return true;
    }

    string getReverse(string s, bool odd)
    {
        if (odd)
        {
            s.pop_back();
        }
        int lo = 0, hi = s.length() - 1;
        while (lo < hi)
        {
            swap(s[lo++], s[hi--]);
        }
        return s;
    }

public:
    string nearestPalindromic(string n)
    {
        int len = n.length();

        if (len == 1)
        {
            return to_string((n[0] - '0') - 1);
        }

        string res = "";
        if (is10__(n))
        {
            for (int i = 0; i < len - 1; i++)
            {
                res += '9';
            }
            return res;
        }
        if (is99__(n))
        {
            res = "1";
            for (int i = 0; i < len - 1; i++)
            {
                res += '0';
            }
            res += '1';
            return res;
        }

        long long half = ((len & 1) ? stoll(n.substr(0, len / 2 + 1)) : stoll(n.substr(0, len / 2)));
        long long greater, smaller, equal;
        if (len & 1)
        {
            greater = stoll(to_string(half + 1) + getReverse(to_string(half + 1), true));
            smaller = stoll(to_string(half - 1) + getReverse(to_string(half - 1), true));
            equal = stoll(to_string(half) + getReverse(to_string(half), true));
        }
        else
        {
            greater = stoll(to_string(half + 1) + getReverse(to_string(half + 1), false));
            smaller = stoll(to_string(half - 1) + getReverse(to_string(half - 1), false));
            equal = stoll(to_string(half) + getReverse(to_string(half), false));
        }

        long long minDiff = LLONG_MAX;
        long long ans;
        if (stoll(n) - smaller < minDiff)
        {
            minDiff = stoll(n) - smaller;
            ans = smaller;
        }
        if (stoll(n) != equal && abs(stoll(n) - equal) < minDiff)
        {
            minDiff = abs(stoll(n) - equal);
            ans = equal;
        }
        if (greater - stoll(n) < minDiff)
        {
            minDiff = greater - stoll(n);
            ans = greater;
        }
        return to_string(ans);
    }
};
int main()
{
    return 0;
}