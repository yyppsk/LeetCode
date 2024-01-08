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
    bool areOccurrencesEqual(string s)
    {
        int frequency[27] = {};
        int commonFrequency = -1;
        for (int i = 0; i < s.size(); i++)
        {
            ++frequency[s[i] - 97];
            if (frequency[s[i] - 97] > 0)
            {
                commonFrequency = frequency[s[i] - 97];
            }
        }
        for (int i = 0; i < 27; i++)
        {
            if (frequency[i] != commonFrequency && frequency[i] != 0)
                return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}