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

TreeNode *findRightMostLastNode(TreeNode *root)
{
    if (!root->right)
    {
        return root;
    }

    return findRightMostLastNode(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    else if (root->right == nullptr)
    {
        return root->left;
    }

    TreeNode *CurrentNodeRightChild = root->right;
    TreeNode *LeftNodelastRight = findRightMostLastNode(root->left);

    LeftNodelastRight->right = CurrentNodeRightChild;

    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val == key)
    {
        return helper(root);
    }

    TreeNode *ptr = root;
    while (root)
    {
        if (root->val > key)
            if (root->left != nullptr && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                // traverse further deep in left
                root = root->left;
            }
        else
        {
            if (root->right != nullptr && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return ptr;
}

int main()
{
    return 0;
}