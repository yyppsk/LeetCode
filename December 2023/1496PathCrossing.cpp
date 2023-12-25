#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

bool isPathCrossing(string path)
{
    // we know that the starting index of this problem will be (0,0)
    // traverse through this path string and pick each direction and move accordingly

    pair<int, int> coord = {0, 0};
    set<pair<int, int>> st;

    for (char &ch : path)
    {

        // cases
        if (ch == 'N')
        {
            // Y axis changes
            coord.second++;
        }
        else if (ch == 'S')
        {
            // Y axis negative
            coord.second--;
        }
        else if (ch == 'E')
        {
            coord.first++;
        }
        else
        {
            coord.first--;
        }
        auto it = st.find(coord);
        cout << coord.first << "," << coord.second << endl;
        if (it != st.end())
        {
            cout << "Found " << coord.first << "," << coord.second << endl;
            return false;
        }
        st.insert(coord);
    }
    return true;
}
int main()
{
    isPathCrossing("NESWW");
    return 0;
}