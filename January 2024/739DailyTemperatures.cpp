#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperaturesBrute(vector<int> &temperatures)
    {
        vector<int> answer;
        for (int i = 0; i < temperatures.size(); i++)
        {
            int pick = temperatures[i];
            bool found = false;
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > pick)
                {
                    answer.push_back(j - i);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                answer.push_back(0);
            }
        }
        return answer;
    }
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;

        vector<int> answer(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                answer[i] = 0;
            }
            else
                answer[i] = st.top() - i;
            st.push(i);
        }
        return answer;
    }
};
int main()
{
    return 0;
}