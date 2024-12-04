#include <bits/bits-stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *prev = root, *curr;
        while (prev)
        {
            curr = prev;
            while (curr && curr->left)
            {
                curr->left->next = curr->right;
                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};

class Solution2
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->left != nullptr)
        {
            root->left->next = root->right;
        }

        if (root->right != nullptr && root->next != nullptr)
        {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};

class Solution3
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node *prev = NULL;
            for (int i = 0; i < n; i++)
            {
                auto top = q.front();
                q.pop();
                top->next = prev;
                prev = top;
                if (top->right)
                {
                    q.push(top->right);
                }
                if (top->left)
                {
                    q.push(top->left);
                }
            }
        }
        return root;
    }
};
int main()
{
    return 0;
}