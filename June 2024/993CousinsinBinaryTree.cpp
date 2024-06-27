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

int findParentandDepth(TreeNode *root, int &parent, int depth, int check)
{
    if (!root)
    {
        return 0;
    }

    if (root->val == check)
    {
        return depth;
    }

    parent = root->val;

    int left = findParentandDepth(root->left, parent, depth + 1, check);

    if (left)
    {
        return left;
    }

    parent = root->val;

    int right = findParentandDepth(root->right, parent, depth + 1, check);

    return right;
}

bool isCousins(TreeNode *root, int x, int y)
{

    if (root->val == x || root->val == y)
        return false;

    int parentX = -1, depthX = 0;

    depthX = findParentandDepth(root, parentX, 0, x);

    int parentY = -1, depthY = 0;

    depthY = findParentandDepth(root, parentY, 0, y);

    if (parentX != parentY && depthX == depthY)
    {
        return true;
    }
    return false;
}
int main()
{
    return 0;
}