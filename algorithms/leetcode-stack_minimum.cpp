/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> numbers, min;

public:
    MinStack() {}

    void push(int val)
    {
        numbers.push(val);
        // Save the minimum value everytime.
        if (min.empty() || min.top() > val)
            min.push(val);
        else
            min.push(min.top());
    }

    void pop()
    {
        numbers.pop();
        min.pop();
    }

    int top()
    {
        return numbers.top();
    }

    int getMin()
    {
        return min.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// MinStack saving indexes (O(n^2)) :
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> numbers, min;

public:
    MinStack() {}

    void push(int val)
    {
        numbers.push(val);
        if (min.empty() || getMin() > val)
            min.push(numbers.size());
    }

    void pop()
    {
        if (!min.empty() && min.top() >= numbers.size())
            min.pop();
        numbers.pop();
    }

    int top()
    {
        return numbers.top();
    }

    int getMin()
    {
        stack<int> temp;
        int ret;
        while (numbers.size() > min.top())
        {
            temp.push(numbers.top());
            numbers.pop();
        }
        ret = numbers.top();
        while (!temp.empty())
        {
            numbers.push(temp.top());
            temp.pop();
        }
        return ret;
    }
};