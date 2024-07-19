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

int sum = 0;
int calculate(TreeNode *curr)
{
    if (!curr)
    {
        return 0;
    }

    // Optional Code
    if (!curr->left && !curr->right)
    {
        int backup = curr->val;
        curr->val = 0;
        return backup;
    }

    int leftSum = calculate(curr->left);
    int rightSum = calculate(curr->right);

    int absDiff = abs(leftSum - rightSum);
    sum += absDiff;
    return curr->val + leftSum + rightSum;
}

int findTilt(TreeNode *root)
{

    if (!root)
    {
        return 0;
    }
    calculate(root);
    return sum;
}

int main()
{
    return 0;
}