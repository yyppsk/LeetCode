#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

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
    int ans = 0;
    int inorder(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        if (root->val >= low && root->val <= high)
        {
            return root->val + inorder(root->left, low, high) + inorder(root->right, low, high);
        }

        if (root->val < low)
        {
            return inorder(root->right, low, high);
        }
        return inorder(root->left, low, high);
    }
    int inorderON(TreeNode *root, int low, int high)
    {
        if (root)
        {
            rangeSumBST(root->left, low, high);
            if (root->val >= low && root->val <= high)
                ans += root->val;
            rangeSumBST(root->right, low, high);
        }
        return ans;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        return inorder(root, low, high);
    }
};
int main()
{
    return 0;
}