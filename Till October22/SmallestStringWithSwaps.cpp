#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int fast_io = []()
{ std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

template <typename keytype>
class UF
{
private:
    vector<keytype> p_;

public:
    UF(size_t size) : p_(size)
    {
        iota(begin(p_), end(p_), 0);
    }

    keytype find(keytype x)
    {
        while (x != p_[x])
        {
            x = p_[x] = p_[p_[x]];
        }
        return x;
    }

    bool link(keytype x, keytype y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        p_[y] = x;
        return true;
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        UF<int> uf(size(s));
        for (const vector<int> &pair : pairs)
        {
            uf.link(pair[0], pair[1]);
        }
        vector<string> cs(size(s));
        for (int i = 0; i < size(s); ++i)
        {
            const int r = uf.find(i);
            cs[r].push_back(s[i]);
        }
        for (int i = 0; i < size(cs); ++i)
        {
            if (!empty(cs[i]))
                sort(begin(cs[i]), end(cs[i]), greater<>());
        }
        for (int i = 0; i < size(s); ++i)
        {
            const int r = uf.find(i);
            s[i] = cs[r].back();
            cs[r].pop_back();
        }
        return s;
    }
};
int main()
{
    return 0;
}