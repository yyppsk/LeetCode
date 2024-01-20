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
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int kaamKaraSahi = 0;
        for (int i = 0; i < hours.size(); i++)
        {
            if (hours[i] >= target)
            {
                kaamKaraSahi++;
            }
        }
        return kaamKaraSahi;
    }
};
int main()
{
    return 0;
}