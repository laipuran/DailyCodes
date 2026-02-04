/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
struct Node
{
    int value;
    Node *previous;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
    Node(int val, Node *previous, Node *next) : value(val), previous(previous), next(next) {}
};

class MyCircularQueue
{
private:
    Node *head, *tail;

public:
    MyCircularQueue(int k)
    {
        head = new Node(0);
        tail = head;
        for (int i = 0; i < k; i++)
        {
            Node *newNode = new Node(0);
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        tail->next = head;
        head->previous = tail;
        tail = head;
    }

    bool enQueue(int value)
    {
        // Remember that the number comes from the tail.
        if (isFull())
            return false;
        tail->value = value;
        tail = tail->next;
        return true;
    }

    bool deQueue()
    {
        // And leaves at the head.
        if (isEmpty())
            return false;
        head = head->next;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return head->value;
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return tail->previous->value;
    }

    bool isEmpty()
    {
        return head == tail;
    }

    bool isFull()
    {
        return tail->next == head;
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
