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
    int maxAncestorDiff(TreeNode *root)
    {
        int minvalue = INT_MAX, maxvalue = INT_MIN;
        return findMinMax(root, minvalue, maxvalue);
        ;
    }

private:
    int findMinMax(TreeNode *root, int minvalue, int maxvalue)
    {
        if (root == nullptr)
        {
            return abs(minvalue - maxvalue);
        }
        minvalue = min(root->val, minvalue);
        maxvalue = max(root->val, maxvalue);
        int left = findMinMax(root->left, minvalue, maxvalue);
        int right = findMinMax(root->right, minvalue, maxvalue);
        return max(left, right);
    }
};
// O(N2)
class Solution_recursion
{
public:
    int maxDiff = INT_MIN;
    int maxAncestorDiff(TreeNode *root)
    {
        findMax(root);
        return maxDiff;
    }

private:
    // fixing one root and then trying all childs to find a difference
    void findMaxHelper(TreeNode *root, TreeNode *child)
    {
        if (root == nullptr)
            return;
        if (child == nullptr)
            return;
        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMaxHelper(root, child->left);
        findMaxHelper(root, child->right);
    }

    void findMax(TreeNode *root)
    {
        if (root == nullptr)
            return;
        findMaxHelper(root, root->left);
        findMaxHelper(root, root->right);

        findMax(root->left);
        findMax(root->right);
    }
};
int main()
{
    return 0;
}