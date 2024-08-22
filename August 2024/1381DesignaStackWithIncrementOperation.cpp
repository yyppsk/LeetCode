#include <bits/bits-stdc++.h>
using namespace std;

class CustomStack
{
    vector<int> stack;
    int maxPossible;

public:
    CustomStack(int maxSize)
    {
        maxPossible = maxSize;
    }

    void push(int x)
    {
        if (stack.size() < maxPossible)
        {
            stack.push_back(x);
        }
    }

    int pop()
    {
        if (!stack.empty())
        {
            int top = stack.back();
            stack.pop_back();
            return top;
        }
        return -1;
    }

    void increment(int k, int val)
    {
        if (stack.size() >= k)
        {
            for (int i = 0; i < k; i++)
            {
                stack[i] += val;
            }
        }
        else
        {

            for (int i = 0; i < stack.size(); i++)
            {
                stack[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
int main()
{
    return 0;
}