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
    int romanToInt(string s)
    {
        unordered_map<char, int> symbol;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;

        int result = symbol[s.back()];

        for (int i = s.length() - 2; i >= 0; --i)
        {
            if (symbol[s[i]] < symbol[s[i + 1]])
            {
                result -= symbol[s[i]];
            }
            else
            {
                result += symbol[s[i]];
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}