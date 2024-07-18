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

/*

Let's say that you have a root with value 1 and the offsprings of the root are leaves and have values 0 and 1 respectively for left and right.
Since integers are represented in binary (base 2) anyway, we can work with the binaries instead of translating it in base 10 every time.

Thus, the first leaf will have value 10 (2 in base 10) and the second will have value 11 (3 in base 10).
In order to compute the first case from 1 from the root and 0 from the leaf, you can take the value 1, multiply it by 2 so that the binary shifts by one to the left (10) and then add the leaf value (10 + 0 = 10). For the second case, the final value will be 10 + 1 = 11.

In my opinion, the operations should be changed into bit operations to be more intuitive (in the sense that we are not really working with arithmetics, we are actually just doing bit manipulation). Thus, this would be sum = (sum<<1) | root.val. The operator << shifts the value to the left by one bit only. Then, instead of adding the value of the node we are considering, we can just OR it: 10 or 0 = 10 and 10 or 1 = 11.

1 0 1

(1)
<<(1)
(10) | 0
(10)

<<(100)
(100) | 1
(101)


*/

int finder(TreeNode *root, int accumulate)
{
    if (!root)
        return 0;
    accumulate = (accumulate << 1) | root->val;

    if (!root->left && !root->right)
        return accumulate;

    return finder(root->left, accumulate) + finder(root->right, accumulate);
}

int sumRootToLeaf(TreeNode *root)
{
    return finder(root, 0);
}
int main()
{
    return 0;
}