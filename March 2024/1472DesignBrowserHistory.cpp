#include <bits/stdc++.h>
using namespace std;
class BrowserHistory
{
public:
    int position = 0;
    vector<std::string> history;

    BrowserHistory(string homepage) { history.push_back(homepage); }

    void visit(string url)
    {
        position++;
        history.resize(position);
        history.push_back(url);
    }

    string back(int steps)
    {
        position = max(0, position - steps);
        return history[position];
    }

    string forward(int steps)
    {
        position = min((int)history.size() - 1, position + steps);
        return history[position];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
int main()
{
    return 0;
}