#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string restoreString(string s, vector<int> &indices)
{
    string t = s;
    for (int i = 0; i < indices.size(); i++)
    {
        swap(s[indices[i]], t[i]);
    }
    return s;
}
int main()
{
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    cout << restoreString(s, indices);
    return 0;
}