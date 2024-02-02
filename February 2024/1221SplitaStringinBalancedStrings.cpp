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
    int balancedStringSplit(string s)
    {
        int balance = 0, result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
            {
                balance++;
            }
            else
            {
                balance--;
            }

            if (balance == 0)
            {
                result++;
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}