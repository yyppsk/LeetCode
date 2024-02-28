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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        traverse(root->left, root->right, 1);
        return root;
    }

    void traverse(TreeNode *node1, TreeNode *node2, int level)
    {
        if (node1 == nullptr || node2 == nullptr)
        {
            return;
        }

        if (level % 2 == 1)
        {
            swap(node1->val, node2->val);
        }
        traverse(node1->left, node2->right, level + 1);
        traverse(node1->right, node2->left, level + 1);
    }
};
int main()
{
}