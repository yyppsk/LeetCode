#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
    int index = -1;
    int i = 0;
    int j = 0;
    int k = 0;
    while (j < haystack.size())
    {
        string build = "";
        if (haystack[j] == needle[k])
        {
            printf("Checking %c == %c : \n", haystack[j], needle[k]);
            j++;
            if (build == needle)
            {
                index = i;
                i = j;
            }
            k++;
        }
        build.push_back(haystack[i]);
        
    }

    return index;
}
int main()
{
    string haystack = "sadbutsad", needle = "sad";
    cout << strStr(haystack, needle);
    return 0;
}