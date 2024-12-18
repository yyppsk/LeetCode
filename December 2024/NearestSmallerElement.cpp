#include <bits/bits-stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    return res;
}

int main()
{
    return 0;
}