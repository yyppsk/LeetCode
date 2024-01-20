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
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> arr;
        for (int i = 0; i < words.size(); i++)
        {
            bool hai = false;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (words[i][j] == x)
                {
                    hai = true;
                }
            }
            if (hai)
            {
                arr.push_back(i);
            }
        }
        return arr;
    }
};
int main()
{
    return 0;
}