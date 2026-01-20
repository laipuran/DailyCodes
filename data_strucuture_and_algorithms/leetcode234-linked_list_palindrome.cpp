/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *forth = head, *back = head;
        while (back != nullptr && back->next != nullptr)
        {
            forth = forth->next;
            back = back->next->next;
        }
        ListNode *nextNode = forth->next;
        forth->next = nullptr;
        // Remember to cut to cycle: medium.left -> medium <- medium.next
        while (nextNode != nullptr)
        {
            ListNode *next = nextNode->next;
            nextNode->next = forth;
            forth = nextNode;
            nextNode = next;
        }
        back = forth;
        forth = head;
        while (back != nullptr && forth != nullptr)
        {
            if (back->val != forth->val)
                return false;
            forth = forth->next;
            back = back->next;
        }
        return true;
    }
};
// @lc code=end
