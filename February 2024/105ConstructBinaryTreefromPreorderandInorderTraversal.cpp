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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inordermap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inordermap[inorder[i]] = i;
        }

        TreeNode *root = builder(preorder, 0, preorder.size() - 1, inorder, 0,
                                 inorder.size() - 1, inordermap);
        return root;
    }

private:
    TreeNode *builder(vector<int> &preorder, int preorderStart, int preorderEnd,
                      vector<int> &inorder, int inorderStart, int inorderEnd,
                      unordered_map<int, int> &inordermap)
    {

        if (preorderStart > preorderEnd || inorderStart > inorderEnd)
        {
            return nullptr;
        }

        // new node

        TreeNode *root = new TreeNode(preorder[preorderStart]);
        int inorderRoot = inordermap[root->val];
        int numbersOnLeft = inorderRoot - inorderStart;

        root->left =
            builder(preorder, preorderStart + 1, preorderStart + numbersOnLeft,
                    inorder, inorderStart, inorderRoot - 1, inordermap);
        root->right =
            builder(preorder, preorderStart + numbersOnLeft + 1, preorderEnd,
                    inorder, inorderRoot + 1, inorderEnd, inordermap);
        return root;
    }
};
int main()
{
    return 0;
}