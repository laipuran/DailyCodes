/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(), *node = dummy;
        ListNode *ptr1 = list1, *ptr2 = list2;
        while (true)
        {
            ListNode **ptrMin = nullptr;
            if (ptr1 != nullptr && ptr2 != nullptr)
                ptrMin = ptr1->val < ptr2->val ? &ptr1 : &ptr2;
            else if (ptr1 != nullptr)
                ptrMin = &ptr1;
            else if (ptr2 != nullptr)
                ptrMin = &ptr2;
            else
                break;

            node->next = *ptrMin;
            *ptrMin = (*ptrMin)->next;
            node = node->next;
            node->next = nullptr;
        }
        auto head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end
// A short version provided by Gemini:
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(), *node = dummy;

        while (l1 && l2)
        {
            ListNode **ppTarget = (l1->val < l2->val) ? &l1 : &l2;
            node->next = *ppTarget;
            *ppTarget = (*ppTarget)->next;
            node = node->next;
        }

        node->next = l1 ? l1 : l2;

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

// A recurrsion version provided by Gemini:
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};