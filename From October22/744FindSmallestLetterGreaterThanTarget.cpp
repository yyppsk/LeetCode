#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int start = 0;
    int ans;
    int end = letters.size() - 1;
    int flag = 0;
    if (target >= letters[end])
    {
        return letters[0];
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
        }
        if (letters[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        if (mid > end)
        {
            flag = 1;
        }
    }
    return ans;
}
int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'j';
    cout << nextGreatestLetter(letters, target);
    return 0;
}