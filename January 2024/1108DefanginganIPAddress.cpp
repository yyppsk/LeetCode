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
    string defangIPaddr(string address)
    {
        string result = "";
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] != '.')
            {
                result.push_back(address[i]);
            }
            else
            {
                result.push_back('[');
                result.push_back('.');
                result.push_back(']');
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}