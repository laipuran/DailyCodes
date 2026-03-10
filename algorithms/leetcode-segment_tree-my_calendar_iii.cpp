/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
#include <unordered_map>
#include <cmath>
using namespace std;

struct Node
{
    int max;
    int lazy;
    Node *left, *right;
    Node() : max(0), lazy(0), left(nullptr), right(nullptr) {}
};

class MyCalendarThree
{
private:
    Node *root;

    void update(Node *&node, int begin, int end, int l, int r, int val)
    {
        if (node == nullptr)
            node = new Node();

        if (begin >= l && end <= r)
        {
            node->max += val;
            node->lazy += val;
            return;
        }

        pushDown(node);

        int mid = begin + ((end - begin) >> 1);
        if (mid >= l)
            update(node->left, begin, mid, l, r, val);
        if (mid < r)
            update(node->right, mid + 1, end, l, r, val);

        node->max = max(node->left == nullptr ? 0 : node->left->max, node->right == nullptr ? 0 : node->right->max);
    }

    void pushDown(Node *node)
    {
        if (node->left == nullptr)
            node->left = new Node();
        if (node->right == nullptr)
            node->right = new Node();

        if (node->lazy == 0)
            return;

        node->left->lazy += node->lazy;
        node->right->lazy += node->lazy;

        node->left->max += node->lazy;
        node->right->max += node->lazy;

        node->lazy = 0;
    }

public:
    MyCalendarThree() { root = new Node(); }

    int book(int startTime, int endTime)
    {
        update(root, 0, 1e9, startTime, endTime - 1, 1);
        return root->max;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
