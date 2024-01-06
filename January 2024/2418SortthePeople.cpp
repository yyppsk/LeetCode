#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        map<int, string, greater<int>> sortedmp;
        for (int i = 0; i < names.size(); i++)
        {
            sortedmp[heights[i]] = names[i];
        }
        vector<string> answer;
        for (auto &ele : sortedmp)
        {
            answer.push_back(ele.second);
        }
        return answer;
    }
};
int main()
{
    return 0;
}