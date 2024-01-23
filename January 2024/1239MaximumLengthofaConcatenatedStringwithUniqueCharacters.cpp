#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
std::unordered_set<char> uniqueChars;
int maxLength2(vector<string> &arr, int idx, int &ans, string constructed)
{
    if (idx == arr.size())
    {
        int size = constructed.size();
        cout << constructed << " " << endl;
        ans = max(ans, size);
        return ans;
    }

    for (char ch : constructed)
    {
        uniqueChars.insert(ch);
    }
    constructed += arr[idx];
    maxLength2(arr, idx + 1, ans, constructed);
    if (constructed.size() >= arr[idx].size())
        constructed.erase(constructed.end() - arr[idx].size(), constructed.end());
    maxLength2(arr, idx + 1, ans, constructed);
    return ans;
}

int maxLength3(vector<string> &arr, string str = "", int index = 0)
{
    // Use set to check if the string contains all unique characters
    unordered_set<char> s(str.begin(), str.end());
    if (s.size() != ((int)str.length()))
        return 0;

    int ret = str.length();
    for (int i = index; i < arr.size(); i++)
        ret = max(ret, maxLength3(arr, str + arr[i], i + 1));

    return ret;
}
int maxFindLength(const vector<string> &arr, int idx, int mask)
{
    if (idx == arr.size())
    {
        return 0;
    }

    int includeLength = 0;

    // Check if the current word has unique characters and does not share
    // characters with previous words
    bool isValid = true;
    int wordMask = 0;
    for (char ch : arr[idx])
    {
        int bit = 1 << (ch - 'a');
        cout << ch << ": " << bit << endl;
        if ((wordMask & bit) > 0)
        {
            isValid = false;
            break;
        }
        wordMask |= bit;
        cout << "Wordmask |= bit : " << wordMask << endl;
    }

    if (isValid && ((wordMask & mask) == 0))
    {
        includeLength =
            arr[idx].size() + maxFindLength(arr, idx + 1, mask | wordMask);
    }

    // Exclude the current word
    int excludeLength = maxFindLength(arr, idx + 1, mask);

    // Return the maximum of including and excluding the current word
    return max(includeLength, excludeLength);
}
int main()
{
    vector<string> arr = {"bcd", "queer", "lolkingdom"};
    unordered_set<char> uniqueChars;
    // cout << maxLength(arr, 0, uniqueChars, "") << endl;

    return 0;
}