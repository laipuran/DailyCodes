/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode();
        // Avoid problems when deleting from the head.
        dummy->next = head;

        ListNode *forward = dummy, *backward = dummy;
        for (int i = 0; i < n; i++)
            backward = backward->next;
        // Now there's n nodes between backward and forward.
        while (backward != nullptr && backward->next != nullptr)
        {
            forward = forward->next;
            backward = backward->next;
        }
        // The forward->next node is the one we want to delete.
        ListNode *del = forward->next;
        forward->next = forward->next->next;
        ListNode *ret = dummy->next;
        delete del, dummy;
        return ret;
    }
};
// @lc code=end
