/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue
{
private:
    int *array;
    int head, tail;
    int size;

public:
    MyCircularQueue(int k)
    {
        array = new int[k + 1];
        head = tail = 0;
        size = k + 1;
    }

    bool enQueue(int value)
    {
        if (this->isFull())
            return false;
        array[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    bool deQueue()
    {
        if (this->isEmpty())
            return false;
        head = (head + 1) % size;
        return true;
    }

    int Front()
    {
        if (this->isEmpty())
            return -1;
        return array[head];
    }

    int Rear()
    {
        if (this->isEmpty())
            return -1;
        return array[(tail + size - 1) % size];
        // Be aware of the negative number before a mod.
    }

    bool isEmpty()
    {
        return tail == head;
    }

    bool isFull()
    {
        return (tail + 1) % size == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
