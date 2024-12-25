#include <bits/bits-stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS
vector<int> largestValues_dfs(TreeNode *root)
{
    vector<int> res;
    int level = 0;
    traverse(root, res, level);
    return res;
}

void traverse(TreeNode *root, vector<int> &res, int level)
{
    if (root == nullptr)
        return;

    if (res.size() == level)
    {
        res.push_back(root->val);
    }
    else
    {
        res[level] = max(res[level], root->val);
    }

    traverse(root->left, res, level + 1);
    traverse(root->right, res, level + 1);
}

// BFS
vector<int> largestValues(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    queue<TreeNode *> q;
    vector<int> res;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        long long rowMax = LONG_LONG_MIN;
        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();

            rowMax = max((long long)curr->val, rowMax);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        res.push_back((int)rowMax);
    }

    return res;
}
int main()
{
    return 0;
}