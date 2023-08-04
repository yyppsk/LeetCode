#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int start = 0, end = s.size() - 1;
        // Trying to reverse the stuff without touching the stuff which is restricted
        while (start <= end)
        {
            if (isalpha(s[start]) && isalpha(s[end]))
            {
                swap(s[start], s[end]);
                start++, end--;
            }
            else
            {
                if (!isalpha(s[start]))
                    start++;
                if (!isalpha(s[end]))
                    end--;
            }
        }
        return s;
    }
};
int main()
{
    return 0;
}