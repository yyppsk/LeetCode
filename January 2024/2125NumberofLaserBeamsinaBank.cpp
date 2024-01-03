#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int previousRowCount = 0, overall = 0;
        for (auto &row : bank)
        {
            int current = count(begin(row), end(row), '1');
            if (current)
            {
                overall += previousRowCount * current;
                previousRowCount = current;
            }
        }
        return overall;
    }
};
int main()
{
    return 0;
}