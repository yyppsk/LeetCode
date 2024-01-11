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
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> last_index;
        for (int i = 0; i < s.size(); ++i)
        {
            last_index[s[i]] = i;
        }

        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            end = max(end, last_index[s[i]]);
            if (i == end)
            {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};
}
int main()
{
    return 0;
}