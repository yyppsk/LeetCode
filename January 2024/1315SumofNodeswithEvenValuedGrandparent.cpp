#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumEvenGrandparent(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return solve(root, -1, -1);
    }

private:
    int solve(TreeNode *root, int parent, int grandParent)
    {
        if (root == nullptr)
            return 0;
        int left = solve(root->left, root->val, parent);
        int right = solve(root->right, root->val, parent);

        return left + right + (grandParent % 2 ? 0 : root->val);
    }
};
int main()
{
    return 0;
}