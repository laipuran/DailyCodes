/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = 0, lengthB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != nullptr)
        {
            lengthA++;
            ptrA = ptrA->next;
        }
        while (ptrB != nullptr)
        {
            lengthB++;
            ptrB = ptrB->next;
        }
        ptrA = headA;
        ptrB = headB;
        if (lengthA < lengthB)
        {
            int n = lengthB - lengthA;
            for (int i = 0; i < n; i++)
                ptrB = ptrB->next;
        }
        if (lengthA > lengthB)
        {
            int n = lengthA - lengthB;
            for (int i = 0; i < n; i++)
                ptrA = ptrA->next;
        }
        while (ptrA != ptrB)
        {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};

// @lc code=end

// A easier solution provided by Gemini:
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB)
        {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
            // Not using the ptr->next, for using it indeces infinite loop.
            // When there's no intersection, we need break when both are nullptr.
        }
        return ptrA;
    }
};

// Wrong Answer:
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *dummyA = new ListNode(0, headA),
                 *dummyB = new ListNode(0, headB),
                 *ptrA = dummyA, *ptrB = dummyB;
        int lengthB = 0, lengthA = 0;

        while (ptrB->next != nullptr)
        {
            ptrB = ptrB->next;
            lengthB++;
        }

        auto next = dummyA->next;
        ptrA->next = nullptr;
        while (next != nullptr)
        {
            auto before = ptrA;
            ptrA = next;
            next = next->next;
            ptrA->next = before;
            lengthA++;
        }

        auto tail = ptrA;
        ptrB = dummyB;
        int lengthJoin = 0;
        while (ptrB->next != nullptr)
        {
            ptrB = ptrB->next;
            lengthJoin++;
        }

        int k = (lengthB + lengthJoin - lengthA) / 2;
        auto finalNode = dummyB;
        for (int i = 0; i <= k; i++)
            finalNode = finalNode->next;

        next = tail->next;
        ptrA = tail;
        ptrA->next = nullptr;
        while (next != nullptr)
        {
            auto before = ptrA;
            ptrA = next;
            next = next->next;
            ptrA->next = before;
            lengthA++;
        }
        return finalNode;
    }
};
