#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int numUniqueEmails(vector<string> &emails)
{
    unordered_set<string> strset;
    for (int i = 0; i < emails.size(); i++)
    {
        /// cout << emails[i][j];
        int first = i, end = 0;
        string temp = "";
        bool check = true;
        bool atrate = false;
        while (end < emails[first].size())
        {
            if (emails[first][end] == '@')
            {
                check = true;
                atrate = true;
            }
            if (emails[first][end] == '+')
            {
                check = false;
            }
            else if ((check == true) && emails[first][end] != '.' && (!atrate))
            {
                cout << emails[first][end];
                temp += emails[first][end];
            }
            if (atrate)
            {
                cout << emails[first][end];
                temp += emails[first][end];
            }
            end += 1;
        }
        strset.insert(temp);
        cout << endl;
    }
    return strset.size();
}
int main()
{
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    cout << numUniqueEmails(emails);
    return 0;
}