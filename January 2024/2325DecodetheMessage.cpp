#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        char m[128] = {}, current = 'a';
        m[' '] = ' ';
        for (char &ele : key)
        {
            if (m[ele] == 0)
                m[ele] = current++;
        }

        for (int i = 0; i < message.size(); i++)
        {
            message[i] = m[message[i]];
        }
        return message;
    }
};
int main()
{
    return 0;
}