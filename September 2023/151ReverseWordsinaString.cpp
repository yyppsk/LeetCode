#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// dequeue
using namespace std;
string reverseWords(string s)
{
    vector<string> responses;
    string builder = "";
    string res = "";

    for (int potentialStringStart = 0; potentialStringStart < s.size(); potentialStringStart++)
    {

        if (s[potentialStringStart] != ' ')
        {
            // cout << test[potentialStringStart] << " W " << endl;
            builder.push_back(s[potentialStringStart]);
            if (potentialStringStart == s.size() - 1)
            {

                // cout << builder << " Buil " << endl;
                responses.push_back(builder);
            }
        }
        else
        {
            if ((builder.size() != 0))
            {
                // cout << builder << " Buil " << endl;
                responses.push_back(builder);
            }
            builder = "";
        }
    }
    reverse(responses.begin(), responses.end());
    string answer = "";
    for (int i = 0; i < responses.size(); i++)
    {
        answer += responses[i];
        answer += ' ';
    }
    answer.pop_back();
    return answer;
}
int main()
{
    string test = "  a good   example";
    vector<string> responses;
    string builder = "";
    string res = "";

    for (int potentialStringStart = 0; potentialStringStart < test.size(); potentialStringStart++)
    {

        if (test[potentialStringStart] != ' ')
        {
            // cout << test[potentialStringStart] << " W " << endl;
            builder.push_back(test[potentialStringStart]);
            if (potentialStringStart == test.size() - 1)
            {

                // cout << builder << " Buil " << endl;
                responses.push_back(builder);
            }
        }
        else
        {
            if ((builder.size() != 0))
            {
                // cout << builder << " Buil " << endl;
                responses.push_back(builder);
            }
            builder = "";
        }
    }
    // reverse(responses.begin(), responses.end());
    string answer = "";
    for (int i = 0; i < responses.size(); i++)
    {
        answer += responses[i];
        answer += ' ';
    }
    cout << answer;
    return 0;
}