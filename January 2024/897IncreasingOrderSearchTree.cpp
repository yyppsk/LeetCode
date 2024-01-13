#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <deque>
#include <set>
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
    deque<int> dq;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        dq.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *result = new TreeNode();
        TreeNode *ptr = result;
        inorder(root);
        while (!dq.empty())
        {
            ptr->val = dq.front();
            dq.pop_front();
            if (dq.size() == 0)
                break;
            TreeNode *rightchild = new TreeNode();
            ptr->right = rightchild;
            ptr = rightchild;
        }
        return result;
    }
};
class Solution2
{
public:
    void inorder(TreeNode *&result, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(result, root->left);
        result->right = new TreeNode(root->val);
        result = result->right;
        inorder(result, root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *result = new TreeNode();
        TreeNode *ptr = result;
        inorder(result, root);
        return ptr->right;
    }
};
int main()
{
    return 0;
}