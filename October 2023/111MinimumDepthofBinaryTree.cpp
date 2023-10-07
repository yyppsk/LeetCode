#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        // checking if lh & rh are not 0
        return 1 + (lh && rh ? min(lh, rh) : max(lh, rh));
    }
};
int main()
{
    return 0;
}