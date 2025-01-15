#include <bits/bits-stdc++.h>
using namespace std;
class MyCircularQueue
{
public:
    vector<int> queue;
    int currentSize = 0;
    int size;
    int front = 0, rear = -1;
    MyCircularQueue(int k)
    {
        queue.resize(k);
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        rear = (rear + 1) % size;
        currentSize += 1;
        queue[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        currentSize -= 1;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[rear];
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == size;
    }
};
int main()
{
    return 0;
}