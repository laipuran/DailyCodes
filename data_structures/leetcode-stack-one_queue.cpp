/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> circularQueue;
    void moveSizeMinusOne()
    {
        for (int i = 0; i < circularQueue.size() - 1; i++)
        {
            circularQueue.push(circularQueue.front());
            circularQueue.pop();
        }
    }

public:
    MyStack() {}

    void push(int x)
    {
        circularQueue.push(x);
    }

    int pop()
    {
        moveSizeMinusOne();
        int temp = circularQueue.front();
        circularQueue.pop();
        return temp;
    }

    int top()
    {
        moveSizeMinusOne();
        int temp = circularQueue.front();
        circularQueue.push(circularQueue.front());
        circularQueue.pop();
        return temp;
    }

    bool empty()
    {
        return circularQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
