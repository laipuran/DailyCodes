/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
using namespace std;

class Stack
{
public:
    struct Node
    {
        int val;
        Node *next;
        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node *next) : val(val), next(next) {}
    };

    Stack()
    {
        dummy = new Node(0);
        head = dummy;
    }

    ~Stack()
    {
        while (head != nullptr)
        {
            auto newTop = head->next;
            delete head;
            head = newTop;
        }
    }

    bool pop()
    {
        if (head == dummy)
            return false;

        auto newTop = head->next;
        delete head;
        head = newTop;
        return true;
    }

    void push(int val)
    {
        auto newNode = new Node(val, head);
        head = newNode;
    }

    bool isEmpty()
    {
        return head == dummy;
    }

    int top()
    {
        return head->val;
    }

private:
    Node *dummy;
    Node *head;
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // Saving indexes.
        Stack stack;

        int *rightSmaller = new int[n];
        for (int i = 0; i < n; i++)
        {
            rightSmaller[i] = n;

            int current = heights[i];
            while (!stack.isEmpty() && current < heights[stack.top()])
            {
                rightSmaller[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }

        while (stack.pop())
        {
        }

        int *leftSmaller = new int[n];
        for (int i = n - 1; i >= 0; i--)
        {
            leftSmaller[i] = -1;

            int current = heights[i];
            while (!stack.isEmpty() && current < heights[stack.top()])
            {
                leftSmaller[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }

        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int left = leftSmaller[i], right = rightSmaller[i];

            int sum = (right - left - 1) * heights[i];

            max = sum > max ? sum : max;
        }
        return max;
    }
};
// @lc code=end

// Array emulating stack provided by Gemini:
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 0)
            return 0;

        int *stack = new int[n + 1];
        int top = -1;

        int *leftSmaller = new int[n];
        int *rightSmaller = new int[n];

        for (int i = 0; i < n; i++)
        {
            while (top != -1 && heights[i] < heights[stack[top]])
            {
                rightSmaller[stack[top--]] = i;
            }
            stack[++top] = i;
        }
        while (top != -1)
            rightSmaller[stack[top--]] = n;

        for (int i = n - 1; i >= 0; i--)
        {
            while (top != -1 && heights[i] < heights[stack[top]])
            {
                leftSmaller[stack[top--]] = i;
            }
            stack[++top] = i;
        }
        while (top != -1)
            leftSmaller[stack[top--]] = -1;

        long long maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            long long width = rightSmaller[i] - leftSmaller[i] - 1;
            maxArea = max(maxArea, (long long)heights[i] * width);
        }

        delete[] stack;
        delete[] leftSmaller;
        delete[] rightSmaller;

        return (int)maxArea;
    }
};