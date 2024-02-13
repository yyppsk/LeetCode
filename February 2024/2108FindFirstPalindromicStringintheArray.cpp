#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
string firstPalindrome(vector<string> &words)
{
    for (auto &w : words)
        if (equal(begin(w), end(w), rbegin(w)))
            return w;
    return {};
}

string firstPalindrome(vector<string> &words)
{
    for (auto &w : words)
        if (equal(begin(w), end(w), rbegin(w)))
            return w;
    return {};
}
int main()
{
    return 0;
}