#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool canConstruct(string ransomNote, string magazine)
{
    int arr[26] = {0};
    for (int i = 0; i < ransomNote.size(); i++)
    {
        int idx = ransomNote[i] - 97;
        arr[idx]++;
    }
    for (int i = 0; i < magazine.size(); i++)
    {

        int idx = magazine[i] - 97;

        arr[idx] = arr[idx] - 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    string ransomNote = "aa", magazine = "aab";
    cout << canConstruct(ransomNote, magazine);
    return 0;
}