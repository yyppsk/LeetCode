#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                string temp1 = words[i];
                string temp2 = "";
                temp2.push_back(words[j][1]);
                temp2.push_back(words[j][0]);
                if (temp1 == temp2)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}