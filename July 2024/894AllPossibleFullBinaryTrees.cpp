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

unordered_map<int, vector<TreeNode *>> mp;
vector<TreeNode *> construct(int n)
{
    if (n % 2 == 0)
    {
        return {};
    }
    if (n == 1)
    {
        TreeNode *root = new TreeNode();
        return {root};
    }

    vector<TreeNode *> result;

    if (mp.find(n) != mp.end())
    {
        return mp[n];
    }
    for (int i = 1; i < n; i += 2)
    {
        vector<TreeNode *> allLeftSBT = construct(i);
        vector<TreeNode *> allRightSBT = construct(n - i - 1);

        for (auto &leftTree : allLeftSBT)
        {
            for (auto &rightTree : allRightSBT)
            {
                TreeNode *root = new TreeNode();
                root->left = leftTree;
                root->right = rightTree;
                result.push_back(root);
            }
        }
    }

    return mp[n] = result;
}

vector<TreeNode *> allPossibleFBT(int n)
{
    return construct(n);
}
int main()
{

    return 0;
}