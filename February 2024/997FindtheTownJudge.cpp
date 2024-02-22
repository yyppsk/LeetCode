#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int AllPeople = n;
        vector<int> ItrustSomeone(AllPeople + 1);
        vector<int> someoneTrustsMe(AllPeople + 1);

        for (int i = 0; i < trust.size(); i++)
        {
            ItrustSomeone[trust[i][0]]++;
            someoneTrustsMe[trust[i][1]]++;
        }

        for (int possibleJudge = 1; possibleJudge <= AllPeople; possibleJudge++)
        {
            if (someoneTrustsMe[possibleJudge] == AllPeople - 1 && ItrustSomeone[possibleJudge] == 0)
                return possibleJudge;
        }
        return -1;
    }
};
int main()
{
    return 0;
}