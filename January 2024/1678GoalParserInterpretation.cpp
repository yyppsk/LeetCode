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
    string interpret(string command)
    {
        string builder = "";
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'G')
            {
                builder.push_back('G');
            }
            else if (command[i] == '(' && command[i + 1] == ')')
            {
                builder.push_back('o');
            }
            else if (command[i] == '(' && command[i + 1] == 'a')
            {
                builder.push_back('a');
                builder.push_back('l');
            }
        }
        return builder;
    }
};
int main()
{
    return 0;
}