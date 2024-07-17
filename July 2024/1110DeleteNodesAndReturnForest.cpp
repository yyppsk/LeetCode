#include <bits/bits-stdc++.h>
#include <unordered_set>;
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

TreeNode *remover(TreeNode *root, unordered_set<int> st, vector<TreeNode *> &result)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    root->left = remover(root->left, st, result);
    root->right = remover(root->right, st, result);

    if (st.find(root->val) != st.end())
    {
        if (root->left != nullptr)
        {
            result.push_back(root->left);
        }

        if (root->right != nullptr)
        {
            result.push_back(root->right);
        }

        return nullptr;
    }

    else
    {
        return root;
    }
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    vector<TreeNode *> result;
    unordered_set<int> st;
    for (int i = 0; i < to_delete.size(); i++)
    {
        st.insert(to_delete[i]);
    }

    remover(root, st, result);

    if (st.find(root->val) == st.end())
    {
        result.push_back(root);
    }

    return result;
}

int main()
{
    return 0;
}