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
    int divisorSubstrings(int num, int k)
    {
        int count = 0;
        string nums = to_string(num);
        int ptr = 0;
        while (ptr <= nums.size() - k)
        {
            string substring = nums.substr(ptr, k);
            int number = stoi(substring);
            if (number != 0 && num % number == 0)
            {
                count++;
            }
            ptr++;
        }
        return count;
    }
};
int main()
{
    return 0;
}