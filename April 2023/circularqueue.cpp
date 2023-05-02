#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> data;
    int head;
    int tail;

public:
    MyCircularQueue(int k)
    {
        head = -1;
        tail = -1;
    }

    bool enQueue(int value)
    {
        data.push_back(value);
        tail++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        tail++;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return 0;
        else
            return data[head];
    }

    int Rear()
    {
    }

    bool isEmpty()
    {
        if (head == -1 && tail == -1 || head > tail)
            return 1;
        else
            false;
    }

    bool isFull()
    {
    }
};

int main()
{
    //  * Your MyCircularQueue object will be instantiated and called as such:
    MyCircularQueue *obj = new MyCircularQueue(5);
    bool param_1 = obj->enQueue(10);
    cout << param_1 << endl;
    cout << obj->Front() << endl;
    bool param_2 = obj->deQueue();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    return 0;
}