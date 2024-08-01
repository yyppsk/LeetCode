#include <bits/bits-stdc++.h>
using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int count = 0;
    for (const auto &item : items)
    {
        if (ruleKey == "type")
        {
            if (item[0] == ruleValue)
            {
                count += 1;
            }
        }
        else if (ruleKey == "color")
        {
            if (item[1] == ruleValue)
            {
                count += 1;
            }
        }
        else if (ruleKey == "name")
        {
            if (item[2] == ruleValue)
            {
                count += 1;
            }
        }
    }
    return count;
}

int main()
{
    return 0;
}