#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    int size = -1;
    for (auto i : strs)
    {
        cout << i.size() << endl;
        int temp = i.size();
        if (i.size() < size)
            size = temp;
    }
    
    return "";
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}