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
    TreeNode *mergeTreesPreorderRecur(TreeNode *root1, TreeNode *root2)
    {
        // preorder
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
    TreeNode *mergeTreesIterativeDFS(TreeNode *root1, TreeNode *root2)
    {
        // preorder
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        stack<pair<TreeNode *, TreeNode *>> st;
        st.push({root1, root2});

        while (!st.empty())
        {
            pair<TreeNode *, TreeNode *> current = st.top();
            st.pop();
            // process the node first
            current.first->val += current.second->val;

            // if both the nodes are not null add them to the stack for future
            // processing if tree1's node is null return the node of t2 if
            // tree2's node is null return the node of t

            // LEFT TREE
            if (current.first->left == nullptr)
            {
                current.first->left = current.second->left;
                // first node is not null
            }
            else if (current.second->left != nullptr)
            {
                // second node is not null
                st.push({current.first->left, current.second->left});
            }

            // RIGHT TREE

            if (current.first->right == nullptr)
            {
                current.first->right = current.second->right;
            }
            else if (current.second->right != nullptr)
            {
                st.push({current.first->right, current.second->right});
            }
        }
        return root1;
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {

        // ITERATIVE BFS
        // Level Order
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        queue<pair<TreeNode *, TreeNode *>> que;
        que.push({root1, root2});

        while (!que.empty())
        {
            pair<TreeNode *, TreeNode *> current = que.front();
            que.pop();

            current.first->val += current.second->val;

            // if both the nodes are not null add them to the stack for future
            // processing if tree1's node is null return the node of t2 if
            // tree2's node is null return the node of t

            // LEFT TREE
            if (current.first->left == nullptr)
            {
                current.first->left = current.second->left;
                // first node is not null
            }
            else if (current.second->left != nullptr)
            {
                // second node is not null
                que.push({current.first->left, current.second->left});
            }

            // RIGHT TREE

            if (current.first->right == nullptr)
            {
                current.first->right = current.second->right;
            }
            else if (current.second->right != nullptr)
            {
                que.push({current.first->right, current.second->right});
            }
        }
        return root1;
    }
};
int main()
{
    return 0;
}