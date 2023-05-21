// This is a F-ing graph problem 399. Evaluate Division
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<string, unordered_map<string, double>> buildgraph(const vector<vector<string>> &equations, const vector<double> &values)
{
    unordered_map<string, unordered_map<string, double>> gr;
    for (int i = 0; i < equations.size(); i++)
    {
        string dividend = equations[i][0], divisor = equations[i][1];
        double value = values[i];
        gr[dividend][divisor] = value;
        gr[divisor][dividend] = 1.0 / value;
    }
    return gr;
}
void dfs(string node, string &dest, unordered_map<string, unordered_map<string, double>> &gr, unordered_set<string> &vis, double &ans, double temp)
{
    if (vis.find(node) != vis.end())
        return;
    vis.insert(node);
    if (node == dest)
    {
        ans = temp;
        return;
    }
    for (auto neighbour : gr[node])
    {
        dfs(neighbour.first, dest, gr, vis, ans, temp * neighbour.second); 
    }
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, unordered_map<string, double>> gr = buildgraph(equations, values);
    vector<double> final;
    for (auto query : queries)
    {
        string dividend = query[0], divisor = query[1];
        if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end())
            final.push_back(-1.0);
        else
        {
            unordered_set<string> vis;
            double ans = -1, temp = 1.0;
            dfs(dividend, divisor, gr, vis, ans, temp);
            final.push_back(ans);
        }
    }
    return final;
}
int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}}, queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> values = {2.0, 3.0};
    vector<double> ans = calcEquation(equations, values, queries);
    for (const auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}