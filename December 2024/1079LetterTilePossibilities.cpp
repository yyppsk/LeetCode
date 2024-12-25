#include <bits/bits-stdc++.h>
using namespace std;

unordered_map<char, int> frequency;
unordered_set<char> st;
int res = 0;
void all(string curr, int idx, string &tiles)
{
    if (idx == tiles.size())
    {
        return;
    }
    for (auto &ch : st)
    {
        if (frequency[ch] > 0)
        {
            res += 1;
            curr.push_back(ch);
            cout << curr << "\n";

            frequency[ch] -= 1;
            all(curr, idx + 1, tiles);

            curr.pop_back();
            frequency[ch] += 1;
        }
    }
}
int numTilePossibilities(string tiles)
{
    for (int i = 0; i < tiles.size(); i++)
    {
        st.insert(tiles[i]);
        frequency[tiles[i]] += 1;
    }
    all("", 0, tiles);

    return res;
}
int main()
{
    string s = "AAB";
    numTilePossibilities(s);
    return 0;
}