#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{ /*
  int start = 0, second = 0;
  int needlesize = 0;
  int idx = INT_MAX;
  while (start < haystack.size())
  {
      cout << "Comparing " << haystack[start] << " and " << needle[second] << " " << needlesize << endl;
      if (haystack[start] == needle[second])
      {
          idx = min(idx, start);
          needlesize++;
          start++;
          second++;
      }
      else
      {
          idx = INT_MAX;
          needlesize = 0;
          second = 0;
          start++;
      }
      cout << "After Comparing " << haystack[start] << " and " << needle[second] << " " << needlesize << endl;
      if (needlesize == needle.size())
      {
          return idx;
      }
  }
  return -1;
  */
    int m = needle.length();
    int n = haystack.length();

    for (int windowStart = 0; windowStart <= n - m; windowStart++)
    {
        for (int i = 0; i < m; i++)
        {
            if (needle[i] != haystack[windowStart + i])
            {
                break;
            }
            if (i == m - 1)
            {
                return windowStart;
            }
        }
    }

    return -1;
}
int main()
{
    string haystack = "mississippi", needle = "issip";
    cout << strStr(haystack, needle);
    return 0;
}