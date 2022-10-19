#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string reverseString(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
int longestDecomposition(string text)
{
    int start = 0, end = text.size() - 1;
    string build1 = "", build2 = "";
    int count = 0;
    vector<string> ans;
    while ((start < text.size()) && (end > 0))
    {
        build1 += text[start];
        build2 += text[end];
        cout << build1 << ":" << build2 << endl;
        if (build1 == reverseString(build2))
        {
            cout << build1 << ":" << reverseString(build2) << endl;
            ans.push_back(build1);
            ans.push_back(build2);
            build1 = "";
            build2 = "";
        }
        start++;
        end--;
    }
    return ans.size();
}
int main()
{
    string text = "ghiabcdefhelloadamhelloabcdefghi";
    cout << longestDecomposition(text) << endl;
    return 0;
}