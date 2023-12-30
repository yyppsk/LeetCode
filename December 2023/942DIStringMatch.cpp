#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> arr(high + 1, 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I'){
                arr[i] = low++;
            }
            else {
                arr[i] = high--;
            }
        }
        arr[s.size()] = high;
        return arr;   
    }
};
int main()
{
    return 0;
}