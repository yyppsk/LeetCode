#include <bits/bits-stdc++.h>
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
int moves = 0;

void distro(TreeNode *current, TreeNode *prev)
{
    if (!current)
    {
        return;
    }

    distro(current->left, current);
    distro(current->right, current);

    int excess = current->val - 1;

    // If current has excess coins, give them to prev
    if (excess > 0)
    {
        prev->val += excess;
        moves += excess;
        current->val = 1;
    }
    // If current needs coins, take them from prev
    else if (excess < 0)
    {
        prev->val += excess;
        moves -= excess; // add the absolute value of excess to moves
        current->val = 1;
    }
}

int distributeCoins(TreeNode *root)
{
    moves = 0;
    TreeNode dummy(0);
    distro(root, &dummy);
    return moves;
}
int distributeCoins(TreeNode *root)
{
    TreeNode *prev = new TreeNode();
    distro(root, prev);
    return moves;
}
int main()
{
    return 0;
}