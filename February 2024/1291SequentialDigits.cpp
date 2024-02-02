#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;
vector<int> sequentialDigits(int low, int high)
{
    string pick = "123456789";
    int limit = 123456789;
    int i = 0, windowsize = 2;
    string construct = "10";
    vector<int> answer;
    while (stoi(construct) < limit)
    {
        while (i + windowsize <= pick.size())
        {
            construct = pick.substr(i, windowsize);
            int number = stoi(construct);
            if (number >= low && number <= high)
            {
                answer.push_back(number);
            }
            if (number > limit)
                break;
            i++;
        }
        i = 0;
        windowsize++;
    }
    return answer;
};
int main()
{
    sequentialDigits(10, 1000000000);
    return 0;
}