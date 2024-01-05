#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &word)
    {
        unordered_map<char, int> fq;
        for (char &ch : allowed)
        {
            fq[ch]++;
        }
        int count = 0;
        for (int i = 0; i < word.size(); i++)
        {
            bool all = false;
            for (int j = 0; j < word[i].size(); j++)
            {
                if (fq.find(word[i][j]) == fq.end())
                {
                    all = false;
                    break;
                }
                else
                    all = true;
            }
            if (all)
            {
                // cout<<word[i]<<endl;
                count++;
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}