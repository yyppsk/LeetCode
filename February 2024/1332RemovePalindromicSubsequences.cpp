#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int start = 0, end = s.size() - 1;
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return 2;
            }
            start++;
            end--;
        }
        return 1;
    }
};
int main()
{
    return 0;
}