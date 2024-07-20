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

TreeNode *recoverFromPreorder(string input)
{

    vector<TreeNode *> numbers;

    string temp;

    vector<int> level;
    level.push_back(0);

    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] != '-')
        {
            temp += input[i];
        }
        else
        {

            if (!temp.empty())
            {
                TreeNode *root = new TreeNode(stoi(temp));
                numbers.push_back(root);
                temp.clear();
            }

            int dash = 0;
            while (input[i] == '-')
            {
                dash++;
                ++i;
            }
            level.push_back(dash);
            --i;
        }
    }

    if (!temp.empty())
    {
        TreeNode *root = new TreeNode(stoi(temp));
        numbers.push_back(root);
    }

    for (int currentNumber = 1; currentNumber < numbers.size(); currentNumber++)
    {
        for (int previousNumber = currentNumber - 1; previousNumber >= 0; previousNumber--)
        {
            if (level[currentNumber] > level[previousNumber])
            {
                if (!numbers[previousNumber]->left)
                {
                    numbers[previousNumber]->left = numbers[currentNumber];
                }
                else
                {
                    numbers[previousNumber]->right = numbers[currentNumber];
                }
                break; // Break here only if we successfully find a parent
                       // node
            }
        }
    }

    return numbers[0];
}

int main()
{
    string s = "1345-2--3--4-5--6--7";
    recoverFromPreorder(s);
    return 0;
}