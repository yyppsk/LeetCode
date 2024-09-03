#include <bits/bits-stdc++.h>
#include <sstream>
using namespace std;
vector<string> subdomainVisits(vector<string> &cpdomains)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < cpdomains.size(); i++)
    {
        stringstream ss(cpdomains[i]);
        string rep, domain;
        getline(ss, rep, ' ');
        ss >> domain;

        stringstream obj(domain);
        string subDomain;
        string subdomainCopy = domain;
        int subDlength = 0;
        vector<string> parts;
        while (getline(obj, subDomain, '.'))
        {
            parts.push_back(subDomain);
            subDlength += 1;
        }

        cout << "SubDlength = " << subDlength << "\n";
        for (auto &ele : parts)
        {
            cout << ele << " ";
        }
        cout << "\n";

        if (subDlength == 1)
        {
            if (mp.find(parts.back()) == mp.end())
            {
                mp[parts.back()] = stoi(rep);
            }
            else
                mp[parts.back()] += 1;
        }
        else if (subDlength == 2)
        {
            if (mp.find(parts.back()) == mp.end())
            {
                mp[parts.back()] = stoi(rep);
            }
            else
                mp[parts.back()] += 1;

            string temp = parts[0] + "." + parts.back();

            if (mp.find(temp) == mp.end())
            {
                mp[temp] = stoi(rep);
            }
            else
                mp[temp] += 1;
        }
        else
        {
            if (mp.find(parts.back()) == mp.end())
            {
                mp[parts.back()] = stoi(rep);
            }
            else
                mp[parts.back()] += 1;

            string temp = parts[1] + "." + parts.back();

            if (mp.find(temp) == mp.end())
            {
                mp[temp] = stoi(rep);
            }
            else
                mp[temp] += 1;

            if (mp.find(subdomainCopy) == mp.end())
            {
                mp[subdomainCopy] = stoi(rep);
            }
            else
                mp[subdomainCopy] += 1;
        }
    }

    vector<string> result;

    for (auto &ele : mp)
    {
        result.push_back(to_string(ele.second) + " " + ele.first);
    }

    return result;
}
int main()
{
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    subdomainVisits(cpdomains);
    return 0;
}