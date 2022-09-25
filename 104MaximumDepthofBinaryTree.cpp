#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// class def for a tree
class TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;
};
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int right = maxDepth(root->right);
    int left = maxDepth(root->left);
    int final = 1 + max(right, left);
    return final;
}
int main()
{
    TreeNode root;
    maxDepth(&root);
    return 0;
}