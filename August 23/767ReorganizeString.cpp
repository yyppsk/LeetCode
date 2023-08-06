#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        int table[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            table[s[i] - 'a']++;
        }

        int maxFreq = INT_MIN;
        char maxChar;

        for (int i = 0; i < 26; i++)
        {
            if (maxFreq < table[i])
            {
                maxFreq = table[i];
                maxChar = i + 'a';
            }
        }
        int index = 0;
        // placing the most frequent char
        while (maxFreq > 0 && index < s.size())
        {
            s[index] = maxChar;
            maxFreq--;
            index += 2;
        }
        if (maxFreq != 0)
            return "";
        table[maxChar - 'a'] = 0;
        for (int i = 0; i < 26; i++)
        {
            while (table[i] > 0)
            {
                if (index >= s.size()) // We are always +1 step ahead in indexing
                    index = 1;
                s[index] = i + 'a';
                table[i]--;
                index += 2;
            }
        }
        return s;
    }
};
int main()
{
    return 0;
}