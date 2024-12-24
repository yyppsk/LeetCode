#include <bits/bits-stdc++.h>
using namespace std;
vector<string> stringSequence(string target)
{
    vector<string> res;

    string temp = "";
    for (int i = 0; i < target.length(); i++)
    {
        int count = target[i] - 'a';
        cout << count << "\n";
        temp.push_back('a');
        res.push_back(temp);
        for (int k = 0; k < count; k++)
        {
            temp.back()++;
            res.push_back(temp);
            cout << temp << "\n";
        }
    }

    return res;
}
int main()
{
    stringSequence("abc");
    return 0;
}