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
class FindElements
{
public:
    TreeNode *root;

    void recover(TreeNode *node, int val)
    {
        if (node == nullptr)
            return;
        node->val = val;
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

    FindElements(TreeNode *root)
    {
        this->root = root;
        recover(root, 0);
    }

    bool search(TreeNode *node, int target)
    {
        if (node == nullptr)
            return false;
        if (node->val == target)
            return true;

        return search(node->left, target) || search(node->right, target);
    }

    bool find(int target) { return search(root, target); }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
int main()
{
    return 0;
}