#include <bits/bits-stdc++.h>
using namespace std;

int countAsterisks(string s)
{
    int pipeEncounter = 0;
    int ast = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '*' && pipeEncounter != 1)
        {
            ast += 1;
        }
        else if (s[i] == '|' && pipeEncounter == 1)
        {
            pipeEncounter = 0;
        }
        else if (s[i] == '|')
        {
            pipeEncounter += 1;
        }
    }

    return ast;
}
int main()
{
    string s = "yo|uar|e**|b|e***au|tifu|l";
    cout << countAsterisks(s);
    return 0;
}