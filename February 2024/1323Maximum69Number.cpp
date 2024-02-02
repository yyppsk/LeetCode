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
    int maximum69Number(int num)
    {
        std::string number = std::to_string(num);

        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] != '9')
            {
                number[i] = '9';
                int result;
                result = stoi(number);
                return result;
            }
        }
        return num;
    }
};
int main()
{
    return 0;
}