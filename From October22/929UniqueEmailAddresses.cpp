#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int numUniqueEmails(vector<string> &emails)
{
    vector<int> find;
    for (int i = 0; i < emails.size(); i++)
    {
        for (int j = 0; j < emails[i].size(); j++)
        {
            cout << emails[i][j];
            if (emails[i][j] == '@')
            {
                find.push_back(j);
            }
        }
        cout << endl;
    }
    for (auto i : find)
    {
        cout << i << endl;
    }
}
int main()
{
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    cout << numUniqueEmails(emails);
    return 0;
}