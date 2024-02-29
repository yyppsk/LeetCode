#include <bits/stdc++.h>
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

TreeNode *constructPerfectBinaryTree(vector<int> &levelOrder)
{
    if (levelOrder.empty())
        return nullptr;

    TreeNode *root = new TreeNode(levelOrder[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        curr->left = new TreeNode(levelOrder[i++]);
        q.push(curr->left);
        if (i < levelOrder.size())
        {
            curr->right = new TreeNode(levelOrder[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

bool isEvenOddTree(TreeNode *root)
{

    if (!root)
        return false;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        int compare;
        bool even = true;
        if (level % 2 == 0)
        {
            compare = INT_MIN;
        }
        else
        {
            compare = INT_MAX;
            even = false;
        }

        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            cout << node->val << " ";

            if (even)
            {
                if (node->val % 2 == 0 || node->val <= compare)
                {
                    return false;
                }
            }
            else
            {
                if (node->val % 2 == 1 || node->val >= compare)
                {
                    return false;
                }
            }

            compare = node->val;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        level++;
        cout << "\n";
    }

    return true;
}

int main()
{
    vector<int> levelOrder = {
        1,
        10,
        4,
        3,
        5,
        7,
        9,
        12, 10,
        8,
        6, 4, 2};
    TreeNode *root = constructPerfectBinaryTree(levelOrder);
    isEvenOddTree(root);
    return 0;
}