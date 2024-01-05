#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> alphabets = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<char, string> toMorse;
        int k = 0;
        for (char i = 'a'; i <= 'z'; i++)
        {
            toMorse[i] = alphabets[k++];
        }
        set<string> st;
        for (int i = 0; i < words.size(); i++)
        {
            string s = "";
            for (int j = 0; j < words[i].size(); j++)
            {
                s += toMorse[words[i][j]];
            }
            st.insert(s);
        }
        return st.size();
    }
};
int main()
{
    return 0;
}