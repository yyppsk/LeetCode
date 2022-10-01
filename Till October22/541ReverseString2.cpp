#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve()
{
}
int main()
{
    string s = "qvaztjeteytuqzzdcnvdqvaztjeteytuqzzdcnvdzfqbexcebgrdzmoxtrvjqvaztjeteytuqzzdcnvdzfqbexcebgrdzmoxtrvjzfqbexcebgrdzmoxtrvj";
    int n = s.size();
    int k = 3;
    int WindowStart = 0;
    int WindowEnd = n - 1;
    for (int i = 0; i < n; i = i = i + (2 * k))
    {
        WindowStart = i;
        WindowEnd = min((i + k - 1), n - 1);
        while (WindowStart < WindowEnd)
        {
            swap(s[WindowStart], s[WindowEnd]);
            WindowStart++;
            WindowEnd--;
        }
    }
    cout << s;
    return 0;
}