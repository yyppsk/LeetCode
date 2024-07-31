#include <bits/bits-stdc++.h>
using namespace std;

vector<string> result;
void generate(string s, int n)
{
    if (s.size() == n)
    {
        bool valid = true;
        for (int i = 0; i < n - 1; i++)
        {
            string current = s.substr(i, 2);
            if (current[0] != '1' && current[1] != '1')
            {
                valid = false;
            }
        }
        if (valid)
        {
            result.push_back(s);
        }

        return;
    }

    s.push_back('0');
    generate(s, n);
    s.pop_back();
    s.push_back('1');
    generate(s, n);
    s.pop_back();
    return;
}
vector<string> validStrings(int n)
{
    generate("", n);
    return result;
}
int main()
{
    validStrings(3);
    return 0;
}