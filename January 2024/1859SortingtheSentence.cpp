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
    string sortSentence(string s)
    {
        string build = "";
        vector<pair<int, string>> Sentance;
        for (int i = 0; i <= s.size(); i++)
        {

            // Check if the current pointer is at a whitespace, or last index of the string S
            if (s[i] == ' ' || i == s.size())
            {

                // Taking the last charachter of built string (Ex. This1) ==> 1
                // and converting it to integer
                int index = build.back() - '0';

                // Removing the the last charachter of built string (Ex. This1) ==> This
                build.pop_back();

                // Storing our build string to CleanText and pushing it to Sentance array
                //  {index, word}
                string cleanText = build;

                // push the constructed string to the Sentance array
                Sentance.push_back({index, cleanText});
                build = "";
            }
            else
            {

                // constructing the word without whitespaces
                build.push_back(s[i]);
            }
        }

        // for (auto ele : Sentance) {
        //     cout << ele.first << " : " << ele.second << endl;
        // }

        // sort the sentance array on the basis of index {index, word}
        sort(Sentance.begin(), Sentance.end());

        string result;

        // build the final result string with the sorted sentance array
        for (auto &word : Sentance)
        {
            result += (word.second) + " ";
        }
        // remove the extra whitespace added above
        result.pop_back();
        return result;
    }
};
int main()
{
    cout << endl;
    // cout << sortSentence("is2 sentence4 This1 a3");
    return 0;
}