#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
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

TreeNode *populateTree()
{
    // Create nodes for the given values
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    // Return the root node of the populated tree
    return root;
}
bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;
    // cout << "Root " << root->val << " sum : " << sum << endl;
    sum = sum - root->val;
    if (sum == 0 && !root->left && !root->right)
        return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
int main()
{
    TreeNode *root = populateTree();
    int sum = 0;
    hasPathSum(root, 22);
    return 0;
}