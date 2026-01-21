/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        // Be aware of nullptr called in.
        ListNode *node = head;
        int length = 1;
        while (node != nullptr && node->next != nullptr)
        {
            node = node->next;
            length++;
        }
        node->next = head;
        int n = length - k % length;
        for (int i = 0; i < n; i++)
            node = node->next;
        auto newHead = node->next;
        node->next = nullptr;
        return newHead;
    }
};
// @lc code=end
