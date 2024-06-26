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

vector<int> traversal;

TreeNode *balancer(int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(traversal[mid]);

    root->left = balancer(left, mid - 1);
    root->left = balancer(mid + 1, right);

    return root;
}

void extract(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    extract(root->left);
    traversal.push_back(root->val);
    extract(root->right);
}

TreeNode *balanceBST(TreeNode *root)
{
    extract(root);
    balancer(0, traversal.size() - 1);
}

int main()
{
    return 0;
}