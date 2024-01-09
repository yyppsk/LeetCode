#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
using namespace std;

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
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
        return root;
    }

    TreeNode *bstToGst2(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *node = root;
        stack<TreeNode *> st;
        int sum = 0;

        while (!st.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                st.push(node);
                node = node->right;
            }

            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;
            node = node->left;
        }

        return root;
    }
};
int main()
{
    return 0;
}