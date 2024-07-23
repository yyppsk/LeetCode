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

map<pair<int, int>, vector<TreeNode *>> mp;

vector<TreeNode *> treeFinder(int start, int end)
{
    if (start > end)
    {
        return {nullptr};
    }
    if (start == end)
    {
        TreeNode *root = new TreeNode(start);
        return {root};
    }
    if (mp.find({start, end}) != mp.end())
        return mp[{start, end}];

    vector<TreeNode *> result;

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> leftBST = treeFinder(start, i - 1);
        vector<TreeNode *> rightBST = treeFinder(i + 1, end);

        for (const auto &leftTree : leftBST)
        {
            for (const auto &rightTree : rightBST)
            {
                TreeNode *root = new TreeNode(i);
                root->left = leftTree;
                root->right = rightTree;
                result.push_back(root);
            }
        }
    }

    return mp[{start, end}] = result;
}

vector<TreeNode *> generateTrees(int n)
{
    return treeFinder(1, n);
}

int main()
{
    return 0;
}