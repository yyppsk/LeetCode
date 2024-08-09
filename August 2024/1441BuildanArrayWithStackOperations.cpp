#include <bits/bits-stdc++.h>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    vector<string> answer;
    int i = 0;
    int k = 1;
    while (i < target.size() && k <= n)
    {

        if (target[i] == k)
        {
            answer.push_back("Push");
            k++;
        }
        else
        {
            int popcount = 0;
            while (target[i] != k)
            {
                k++;
                popcount++;
                answer.push_back("Push");
            }

            if (target[i] == k)
            {
                while (popcount--)
                {
                    answer.push_back("Pop");
                }
                answer.push_back("Push");
                k++;
            }
        }
        i++;
    }

    return answer;
}
int main()
{
    //["Push","Pop","Push","Push","Push"]
    vector<int> target = {2, 3, 4};
    buildArray(target, 4);
    return 0;
}