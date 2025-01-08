#include <bits/bits-stdc++.h>
using namespace std;
int countPrefixSuffixPairs(vector<string> &words)
{
    int count = 0;

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            int size = words[i].length();
            int size2 = words[j].length();

            if (size > size2)
                continue;
            int k = size - 1, k2 = size2 - 1;
            bool isSuffix = true;

            while (k >= 0 && k2 >= 0)
            {
                if (words[i][k] != words[j][k2])
                {
                    isSuffix = false;
                    break;
                }
                k--;
                k2--;
            }
            bool isPrefix = true;

            k = 0;

            while (k < size)
            {
                if (words[i][k] != words[j][k])
                {
                    isPrefix = false;
                    break;
                }
                k++;
            }

            if (isPrefix && isSuffix)
            {
                cout << words[i] << " is p-s of " << words[j] << "\n";
                count += 1;
            }
        }
    }

    return count;
}
int main()
{
    vector<string> words = {"abc", "abcba", "abccba", "cbabc", "cbaabc", "cbacba", "abc", "abcabc"};
    cout << countPrefixSuffixPairs(words);
    return 0;
}