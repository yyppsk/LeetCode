#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
bool wordPattern(string pattern, string s)
{
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;

    istringstream in(s);
    string word;
    int i = 0, n = pattern.size();

    for (word; in >> word; i++)
    {
        cout << p2i[pattern[i]] << "!=" << w2i[word] << endl;
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false; // If it reaches end before all the words in string 's' are traversed || if values of keys : pattern[i] & word don't match return false

        p2i[pattern[i]] = w2i[word] = i + 1; // Otherwise map to both to a value i+1
    }
    return i == n; // both the lengths should be equal
}
int main()
{
    string pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s);
    return 0;
}