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

class Solution1
{
public:
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr;
        inorder(root1, arr);
        inorder(root2, arr);

        sort(arr.begin(), arr.end());
        return arr;
    }
};

// Two Stacks
class Solution2
{
public:
    void inorder(TreeNode *root, stack<int> &arr)
    {
        if (!root)
        {
            return;
        }
        inorder(root->right, arr);
        arr.push(root->val);
        inorder(root->left, arr);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        stack<int> A, B;
        inorder(root1, A);
        inorder(root2, B);
        vector<int> answer;

        while (!A.empty() && !B.empty())
        {
            if (A.top() < B.top())
            {
                answer.push_back(A.top());
                A.pop();
            }
            else
            {
                answer.push_back(B.top());
                B.pop();
            }
        }

        while (!A.empty())
        {
            answer.push_back(A.top());
            A.pop();
        }

        while (!B.empty())
        {
            answer.push_back(B.top());
            B.pop();
        }

        return answer;
    }
};

// Priority Queue
class Solution3
{
public:
    void inorder(TreeNode *root,
                 priority_queue<int, vector<int>, greater<int>> &arr)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, arr);
        arr.push(root->val);
        inorder(root->right, arr);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        inorder(root1, pq);
        inorder(root2, pq);
        vector<int> answer;

        while (!pq.empty())
        {
            answer.push_back(pq.top());
            pq.pop();
        }

        return answer;
    }
};
int main()
{
    return 0;
}