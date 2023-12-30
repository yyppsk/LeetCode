#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int high;
        for (high = 0; high < word.size(); high++)
        {
            if (word[high] == ch)
            {
                break;
            }
        }
        if (high >= word.size())
        {
            return word;
        }
        int low = 0;
        while (low <= high)
        {
            swap(word[low], word[high]);
            low++, high--;
        }
        return word;
    }
};
int main()
{
    return 0;
}