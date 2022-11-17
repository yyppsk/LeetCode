#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
string removeDuplicates(string s, int k)
{
    vector<pair<char, int>> st;
    st.push_back({'#', 0});
    for (char ch : s)
    {
        if (st.back().first != ch)
        {
            st.push_back({ch, 1});
        }
        else if (++st.back().second == k)
        {
            st.pop_back();
        }
    }
    string res = "";
    for (auto &p : st)
    {
        res.append(p.second, p.first);
    }
    return res;
}
int main()
{
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << removeDuplicates(s, k);
    return 0;
}