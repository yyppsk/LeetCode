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

class Solution
{
public:
    int level[100001] = {}, depth[100001] = {};
    int d1[100001] = {}, d2[100001] = {};
    int traverse(TreeNode *n, int l = 0)
    {
        if (n == nullptr)
            return 0;
        level[n->val] = l;
        depth[n->val] =
            1 + max(traverse(n->left, l + 1), traverse(n->right, l + 1));
        if (d1[l] < depth[n->val])
        {
            d2[l] = d1[l];
            d1[l] = depth[n->val];
        }
        else if (d2[l] < depth[n->val])
            d2[l] = depth[n->val];
        return depth[n->val];
    };
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        traverse(root, 0);
        transform(begin(queries), end(queries), begin(queries), [&](int q)
                  {
            int l = level[q];
            return l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1; });
        return queries;
    }
};

int findHeight(TreeNode *root, int currentHeight, int maxHeight,
               int query)
{
    if (root == nullptr)
    {
        return maxHeight;
    }

    if (root->val == query || (root->left == nullptr && root->right == nullptr))
    {
        maxHeight = max(currentHeight, maxHeight);
        return maxHeight;
    }

    int leftHeight = findHeight(root->left, currentHeight + 1, maxHeight, query);
    int rightHeight = findHeight(root->right, currentHeight + 1, maxHeight, query);

    return max(leftHeight, rightHeight);
}

vector<int> treeQueries(TreeNode *root, vector<int> &queries)
{
    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
        result.push_back(findHeight(root, 0, 0, queries[i]));
    }

    return result;
}

int main()
{
    return 0;
}