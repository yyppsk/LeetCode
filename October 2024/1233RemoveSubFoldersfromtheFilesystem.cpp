#include <bits/bits-stdc++.h>
using namespace std;
vector<string> removeSubfolders(vector<string> &folder)
{
    std::sort(folder.begin(), folder.end(), [](const std::string &a, const std::string &b)
              { return a.length() < b.length(); });
    for (auto &ele : folder)
    {
        cout << ele << " ,";
    }
    cout << "\n";
    unordered_set<string> visited;

    for (int i = 0; i < folder.size(); i++)
    {
        if (folder[i].length() == 2)
        {
            cout << "Put " << folder[i] << " in set\n";
            visited.insert(folder[i]);
        }
        else
        {
            string testString = "";
            int j = 0;
            bool exists = false;
            int k;
            while (j < folder[i].length())
            {
                testString.push_back('/');
                k = j + 1;
                while (folder[i][k] != '/' && k < folder[i].length())
                {
                    testString.push_back(folder[i][k]);
                    k += 1;
                }

                cout << "Checking for " << testString << "\n";
                if (visited.find(testString) != visited.end())
                {
                    cout << "No need to put " << testString << "\n";
                    exists = true;
                    break;
                }
                j = k;
            }

            if (!exists)
            {
                cout << "Put " << testString << " in set\n";
                visited.insert(testString);
            }
        }
    }
    vector<string> result(visited.begin(), visited.end());
    return result;
}
int main()
{
    vector<string> folder = {"/aa/ab/ac/ae", "/aa/ab/af/ag", "/ap/aq/ar/as", "/ap/aq/ar", "/ap/ax/ay/az", "/ap", "/ap/aq/ar/at", "/aa/ab/af/ah", "/aa/ai/aj/ak", "/aa/ai/am/ao"};

    //[/ap/ax/ay/az ,/ap/aq/ar/at ,/ap/aq/ar/as ,/ap/aq/ar ,/ap ,/aa/ai/am/ao ,/aa/ai/aj/ak ,/aa/ab/af/ah ,/aa/ab/af/ag ,/aa/ab/ac/ae]
    //["/aa/ab/af/ag","/aa/ab/af/ah","/aa/ai/am/ao","/aa/ai/aj/ak","/ap","/ap/aq/ar","/aa/ab/ac/ae","/ap/aq/ar/as","/ap/aq/ar/at","/ap/ax/ay/az"]

    //["/aa/ab/ac/ae","/aa/ab/af/ag","/aa/ab/af/ah","/aa/ai/aj/ak","/aa/ai/am/ao","/ap"]
    removeSubfolders(folder);
    return 0;
}