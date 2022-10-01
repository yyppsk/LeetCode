#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int solve(string s, int k)
{
    int maxLength = 0;
    int start = 0;
    unordered_map<char, int> map;
    for (int we = 0; we < s.size(); we++)
    {
        char current = s[we];
        map[current]++;
        while (map.size() > k)
        {
            char leftchar = s[start];
            map[leftchar]--;
            if (map[leftchar] == 0)
                map.erase(leftchar);
            start++;
        }
        maxLength = max(maxLength, we - start + 1);
    }
    return maxLength;
}
int main()
{
    string s = "abcdbebbbaed";
    cout << solve(s, 3);
    return 0;
}