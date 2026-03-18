/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1->val == 0 && l1->next == nullptr && l2->val == 0 && l2->next == nullptr)
            return new ListNode();

        int temp = 0;
        ListNode *p1 = l1, *p2 = l2, head, *ptr = &head;
        while (p1 != nullptr && p2 != nullptr)
        {
            int sum = temp + p1->val + p2->val;
            temp = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != nullptr)
        {
            int sum = temp + p1->val;
            temp = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            int sum = temp + p2->val;
            temp = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            p2 = p2->next;
        }
        if (temp != 0)
            ptr->next = new ListNode(temp);

        return head.next;
    }
};
// @lc code=end
