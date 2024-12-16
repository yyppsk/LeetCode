#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        unordered_set<int> st;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (st.find(ele) == st.end())
            {
                cout << ele << " ";
            }
            st.insert(ele);
        }

        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) == st.end())
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}