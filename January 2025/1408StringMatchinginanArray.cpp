#include <bits/bits-stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    unordered_set<string> st;

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (words[i].length() > words[j].length() || i == j)
                continue;

            int k1 = 0, k2 = 0;

            while (k2 < words[j].length())
            {
                if (words[i][k1] == words[j][k2])
                {
                    k1++;
                    k2++;
                }
                else
                {

                    k2 = k2 - k1 + 1;
                    k1 = 0;
                }

                if (k1 == words[i].length())
                {
                    st.insert(words[i]);
                    break;
                }
            }
        }
    }

    vector<string> result(st.begin(), st.end());
    return result;
}
int main()
{
    vector<string> words = {"eeeet", "eeet"};

    stringMatching(words);
    return 0;
}