/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

// The bottom of the tail stack is only needed in peek and pop,
// so we added a if structure in the fillHead() function.
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> tail, head;
    void fillHead()
    {
        if (head.empty())
        // Move from head only if tail (outStack) is empty.
        {
            while (!tail.empty())
            {
                head.push(tail.top());
                tail.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x)
    {
        // while (!tail.empty())
        // {
        //     head.push(tail.top());
        //     tail.pop();
        // }
        // tail.push(x);
        tail.push(x);
    }

    int pop()
    {
        fillHead();
        int temp = head.top();
        head.pop();
        return temp;
    }

    int peek()
    {
        fillHead();
        return head.top();
    }

    bool empty()
    {
        return tail.empty() && head.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
