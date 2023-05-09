#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}
int vowelStrings(vector<string> &words, int left, int right)
{
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        int check = 0;

        // cout << words[i][j] << " ";
        if (isVowel(words[i][0]))
        {
            check++;
            if (isVowel(words[i][words[i].size() - 1]))
            {
                check++;
                count++;
                check = 0;
            }
        }
    }
    return count;
}
int main()
{
    vector<string> words = {"are", "amy", "u"};
    int left = 0, right = 2;
    cout << vowelStrings(words, left, right);
    return 0;
}