#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
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
    void preorder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> l1, l2;
        preorder(root1, l1);
        preorder(root2, l2);
        // for (auto& ele : l1) {
        //     cout << ele << " ";
        // }
        // cout << "\n";
        // for (auto& ele : l2) {
        //     cout << ele << " ";
        // }
        if (l1 == l2)
            return true;
        return false;
    }
};
int main()
{
    return 0;
}