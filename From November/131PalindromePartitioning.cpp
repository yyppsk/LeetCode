#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool ispallindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (s == temp)
        return true;
    return false;
}
void rec(string s, vector<string> temp, vector<vector<string>> &answer)
{
    cout << "String " << s << endl;
    if (s.size() < 1)
    {
        answer.push_back(temp);
        return;
    }
    for(int i = 0; i < )
    if (ispallindrome(s))
    {
        temp.push_back(s);
    }
    s.pop_back();
    rec(s, temp, answer);
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> answer;
    vector<string> temp;
    rec(s, temp, answer);
    cout << "Rec done" << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer.size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return {{}};
}
int main()
{
    string s = "aab";
    partition(s);
    return 0;
}