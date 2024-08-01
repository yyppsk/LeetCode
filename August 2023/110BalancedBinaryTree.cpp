#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
bool isBalanced(TreeNode *root)
{
    return dfsTraversalForHeight(root) != -1;
}
int dfsTraversalForHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = dfsTraversalForHeight(root->left);
    if (left == -1)
        return -1;
    int right = dfsTraversalForHeight(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
int main()
{
    return 0;
}