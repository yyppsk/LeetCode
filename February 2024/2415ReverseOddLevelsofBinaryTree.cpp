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

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        traverse(root->left, root->right, 1);
        return root;
    }

    void traverse(TreeNode *node1, TreeNode *node2, int level)
    {
        if (node1 == nullptr || node2 == nullptr)
        {
            return;
        }

        if (level % 2 == 1)
        {
            swap(node1->val, node2->val);
        }
        traverse(node1->left, node2->right, level + 1);
        traverse(node1->right, node2->left, level + 1);
    }
};

// Please upvote if it helps :)
class SolutionBFS
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> q;
        vector<int> values;
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (level % 2)
                    node->val = values[sz - i - 1];

                if (node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if (node->right)
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            values = temp;
            level++;
        }
        return root;
    }
};
int main()
{
}