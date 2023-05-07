#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int firstUniqChar(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 97;
        arr[idx]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 97;
        if (arr[idx] == 1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string s = "leetcode";
    cout << firstUniqChar(s);
    return 0;
}