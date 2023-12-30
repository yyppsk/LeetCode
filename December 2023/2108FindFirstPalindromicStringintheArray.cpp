#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        string ans = "";
        for (auto &word : words)
        {
            int low = 0, high = word.size() - 1;
            bool pallindrome = true;
            while (low < high)
            {
                if (word[low++] != word[high--])
                {
                    pallindrome = false;
                }
            }
            if (pallindrome == true)
            {
                return word;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}