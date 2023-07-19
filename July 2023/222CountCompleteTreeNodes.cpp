#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
int cnt = 0;
void inorder(TreeNode *ptr)
{
    if (ptr == nullptr)
    {
        return; // Base case: return if the node is null
    }
    inorder(ptr->left);
    cnt++;
    inorder(ptr->right);
}
int countNodes(TreeNode *root)
{
    inorder(root);
    return cnt;
}
int main()
{
    return 0;
}