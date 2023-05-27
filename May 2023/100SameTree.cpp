#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
void preorder(TreeNode *root, vector<int> &traversal)
{
    traversal.push_back(root->val);
    preorder(root->left, traversal);
    preorder(root->right, traversal);
}
int main()
{
    // Creating Tree p
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Creating Tree q
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Printing the values of the trees
    std::cout << "Tree p: " << p->val << " " << p->left->val << " " << p->right->val << std::endl;
    std::cout << "Tree q: " << q->val << " " << q->left->val << " " << q->right->val << std::endl;

    // Clean up the memory by deleting the nodes (optional)
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;
    return 0;
}