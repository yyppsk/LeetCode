#include <bits/bits-stdc++.h>
using namespace std;
int minimizedStringLength(string s)
{
    unordered_set<int> st(s.begin(), s.end());
    return st.size();
}
int main()
{
    return 0;
}