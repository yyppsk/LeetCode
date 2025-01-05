#include <bits/bits-stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<int> &shifts)
{
    int size = s.length();
    vector<int> operations(size, 0);
    operations[size - 1] = shifts.back() % 26;

    for (int i = s.length() - 2; i >= 0; i--)
    {
        operations[i] = (shifts[i] % 26) + (operations[i + 1] % 26);
    }

    for (int i = 0; i < operations.size(); i++)
    {
        // cout << operations[i] << " ";
        s[i] = (s[i] - 'a' + operations[i]) % 26 + 'a';
    }
    return s;
}
// No space, not big diff

string shiftingLetters(string s, vector<int> &shifts)
{
    int size = s.length();
    // vector<int> operations(size, 0);
    // operations[size - 1] = shifts.back() % 26;

    // for (int i = s.length() - 2; i >= 0; i--) {
    //     operations[i] = (shifts[i] % 26) + (operations[i + 1] % 26);
    // }

    for (int i = s.length() - 2; i >= 0; i--)
    {
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (int i = 0; i < shifts.size(); i++)
    {
        // cout << operations[i] << " ";
        s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
    }
    return s;
}
int main()
{
    string s = "abc";
    vector<int> sh = {3, 5, 9};

    shiftingLetters(s, sh);
    return 0;
}