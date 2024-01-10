#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> adj;
        buildGraph(adj, -1, root);

        // BFS
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);

        int minute = 0;
        while (!q.empty())
        {
            int n = q.size(); // current level
            while (n--)
            {
                int current = q.front();
                q.pop();
                for (int &neighbour : adj[current])
                {
                    if (vis.find(neighbour) == vis.end())
                    {
                        q.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
            minute++;
        }
        return minute - 1;
    }

private:
    void buildGraph(unordered_map<int, vector<int>> &adj, int parent,
                    TreeNode *curr)
    {
        if (curr == NULL)
        {
            return;
        }

        if (parent != -1)
        {
            adj[curr->val].push_back(parent);
        }

        if (curr->left)
        {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right)
        {
            adj[curr->val].push_back(curr->right->val);
        }
        buildGraph(adj, curr->val, curr->left);
        buildGraph(adj, curr->val, curr->right);
    }
};
int main()
{
    return 0;
}