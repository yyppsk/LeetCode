#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    static bool compare(pair<char, int> &p1, pair<char, int> &p2)
    {
        return p1.second > p2.second;
    }
    string frequencySort(string s)
    {
        // Intution 1
        /*
        Seems to be a problem that can leverage a data structure that would either require storing
        the frequencies in some orderly fashion
        can sorting work? I guess not because that will give
        Output
        "Aabb"
        Expected
        "bbAa"
        but sorting has to be done over the frequency not the element itself
        */
        vector<pair<char, int>> frequencyMap(256);
        for (const char &ch : s)
        {
            frequencyMap[ch].first = ch;
            frequencyMap[ch].second += 1;
            // ensure that the frequency of each charachter is assigned
            // to some index in the vector {0..255}
        }

        sort(frequencyMap.begin(), frequencyMap.end(), compare);
        string answer = "";
        for (const auto &element : frequencyMap)
        {
            for (int j = 0; j < element.second; j++)
            {
                answer += element.first;
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}