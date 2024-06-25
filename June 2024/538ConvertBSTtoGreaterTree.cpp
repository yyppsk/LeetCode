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

int NodeAccumulator(TreeNode *root, int &sum)
{
    if (root == nullptr)
        return sum;

    NodeAccumulator(root->right, sum);
    sum += root->val;
    root->val = sum;
    NodeAccumulator(root->left, sum);

    return sum;
}

TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;

    NodeAccumulator(root, sum);

    return root;
}

int main()
{
    return 0;
}