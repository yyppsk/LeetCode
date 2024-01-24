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
    int getMinSwaps(string num, int k)
    {
        string og = num;
        while (k--)
        {
            next_permutation(num.begin(), num.end());
        }

        return minsteps(og, num);
    }

private:
    int minsteps(string s1, string s2)
    {
        int size = s1.length();
        int i = 0, j = 0;
        int result = 0;

        while (i < size)
        {
            j = i;
            while (s1[j] != s2[i])
            {
                j++;
                // J keeps moving until we find the position for the
                // wrong element in the sequence
                //     j
                // 5 1 4 2
                // 5 4 2 1
                //   i
                // now obviously we will try to move j towards left end or Ith end
                // because solution is demanding adjacent swaps
            }

            while (i < j)
            {
                swap(s1[j], s1[j - 1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }
};
int main()
{
    return 0;
}