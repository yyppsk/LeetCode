#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> partitionLabels(string s)
{
    unordered_map<char, int> lastseen;
    int start = 0;
    int end = 0, i = 0;
    int j = 0;
    vector<int> ans;
    for (int i = 0; i <= s.size() - 1; i++)
    {
        printf("Storing %c when i = %d \n", s[i], i);
        lastseen[s[i]] = i;
    }
    for (auto i : lastseen)
        cout << i.first << " " << i.second << endl;
    for (int k = 0; k < s.size(); k++)
    {
        j = lastseen[s[k]];
        end = j;
        printf("Start at : %d J at %d end at %d\n", start, j, end);
        if (lastseen[s[k]] <= end)
            continue;
        else if (lastseen[s[k]] > end)
        {
            j = lastseen[s[k]];
            end = j;
        }
    }
}
int main()
{
    string s = "ababcbacadefegdehijhklij";
    partitionLabels(s);
    return 0;
}