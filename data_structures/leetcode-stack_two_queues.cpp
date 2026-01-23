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
    queue<int> first, second;
    void moveSizeMinusOne()
    {
        while (first.size() > 1)
        {
            second.push(first.front());
            first.pop();
        }
    }

public:
    MyStack() {}

    void push(int x)
    {
        first.push(x);
    }

    int pop()
    {
        moveSizeMinusOne();
        int temp = first.front();
        first = second;
        second = queue<int>();
        return temp;
    }

    int top()
    {
        moveSizeMinusOne();
        int temp = first.front();
        second.push(first.front());
        first = second;
        second = queue<int>();
        return temp;
    }

    bool empty()
    {
        return first.empty();
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
