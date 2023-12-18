#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> st2;
unordered_set<string> st1;
void helper(string str, int n, int idx, string &result)
{
    if (idx == n)
    {
        cout << result << " " << endl;
        st1.insert(result);
        return;
    }
    result.push_back(str[idx]);
    helper(str, n, idx + 1, result);
    result.pop_back();
    helper(str, n, idx + 1, result);
}

void helper2(string str, int n, int idx, string &result)
{
    if (idx == n)
    {
        cout << result << " " << endl;
        st2.insert(result);
        return;
    }

    result.push_back(str[idx]);
    helper2(str, n, idx + 1, result);
    result.pop_back();
    helper2(str, n, idx + 1, result);
}
string moreSubsequence(int n, int m, string a, string b)
{
    string r1 = "";
    string r2 = "";
    helper(a, n, 0, r1);
    helper2(b, m, 0, r2);
    // cout << st1.size() << " : " << st2.size() << endl;
    if (st1.size() >= st2.size())
    {
        return a;
    }
    else
        return b;
}

// way 2
string moreSubsequence(int n, int m, string a, string b)

{

    set<char> s1, s2;

    for (int i = 0; i < n; i++)

        s1.insert(a[i]);

    for (int i = 0; i < m; i++)

        s2.insert(b[i]);

    if (s1.size() == s2.size())

        if (a.size() == b.size())

            return a;

        else if (a.size() > b.size())

            return a;

        else
            return b;

    else

        if (s1.size() < s2.size())

        return b;

    else
        return a;
}
int main()
{
    cout << moreSubsequence(1, 3, "f", "eeg");
    return 0;
}