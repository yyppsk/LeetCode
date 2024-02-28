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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            root = queue.front();
            queue.pop();
            if (root->right != nullptr)
                queue.push(root->right);
            if (root->left != nullptr)
                queue.push(root->left);
        }
        return root->val;
    }
};
int main()
{
    return 0;
}