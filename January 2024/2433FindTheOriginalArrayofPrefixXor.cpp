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
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> result;
        result.push_back(pref[0]);

        // if you have an XOR equation of the form A⊕X=B,
        // you can find X by XORing both sides with A
        int prefix = pref[0];
        for (int i = 1; i < pref.size(); i++)
        {

            int x = pref[i] ^ prefix;

            prefix = prefix ^ x;
            result.push_back(x);
        }
        return result;
    }
};
int main()
{
    return 0;
}