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
    bool halvesAreAlike(string s)
    {
        int counta = 0, countb = 0;
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            if (s[low] == 'a' || s[low] == 'e' || s[low] == 'i' ||
                s[low] == 'o' || s[low] == 'u' || s[low] == 'A' ||
                s[low] == 'E' || s[low] == 'I' || s[low] == 'O' ||
                s[low] == 'U')
            {
                counta++;
            }
            if (s[high] == 'a' || s[high] == 'e' || s[high] == 'i' ||
                s[high] == 'o' || s[high] == 'u' || s[high] == 'A' ||
                s[high] == 'E' || s[high] == 'I' || s[high] == 'O' ||
                s[high] == 'U')
            {
                countb++;
            }
            low++, high--;
        }
        return counta == countb;
    }
};
int main()
{
    return 0;
}