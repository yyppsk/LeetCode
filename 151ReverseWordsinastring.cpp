#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str = " a good example     ";
    string extra = "";
    bool spaceisone = 1;
    for (int i = str.size() - 1; i > 0; i--)
    {
        if (str[i] != ' ')
        {
            spaceisone = false;
            extra.push_back(str[i]);
        }
    }
    cout << extra;
    return 0;
}