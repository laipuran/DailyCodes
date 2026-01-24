/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

/**
 * [Mathematical Proof: Finding the Cycle Entry Point]
 * * Let:
 * - 'a' be the distance from the Start to the Cycle Entry.
 * - 'b' be the distance from the Cycle Entry to the Meeting Point.
 * - 'L' be the total length of the cycle.
 * * When slow and fast pointers meet:
 * 1. Slow pointer distance: S = a + b
 * 2. Fast pointer distance: F = a + b + nL (where n is the number of loops, n >= 1)
 * 3. Relationship: F = 2S (fast is twice as fast as slow)
 * * Derivation:
 * a + b + nL = 2(a + b)
 * a + b = nL
 * a = nL - b
 * a = (n-1)L + (L - b)
 * * Conclusion:
 * The distance from the Start to the Entry (a) is equivalent to 
 * walking from the Meeting Point to the Entry (L - b), plus potentially 
 * multiple full loops (n-1) around the cycle.
 * * Strategy:
 * After the first meeting, reset one pointer to Head and keep the other 
 * at the Meeting Point. Move both at the same speed (1 step). 
 * They will eventually collide at the Cycle Entry.
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
            // The two ptrs meet.
            {
                slow=head;
                while(true){
                    
                    if(slow==fast)return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        return nullptr;
    }
};
// @lc code=end