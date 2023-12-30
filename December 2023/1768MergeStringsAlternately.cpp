#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int ptr1 = 0;
        int ptr2 = 0;
        string answer = "";
        while (ptr1 < word1.size() && ptr2 < word2.size())
        {
            answer.push_back(word1[ptr1]);
            answer.push_back(word2[ptr2]);
            ptr1++, ptr2++;
        }

        while (ptr1 < word1.size())
        {
            answer.push_back(word1[ptr1]);
            ptr1++;
        }
        while (ptr2 < word2.size())
        {
            answer.push_back(word2[ptr2++]);
        }
        return answer;
    }
};
int main()
{
    return 0;
}