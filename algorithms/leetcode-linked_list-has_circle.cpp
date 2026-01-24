/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

// Standard solution provided by Gemini
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Boundary check
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Initialize
        ListNode *slow = head;
        ListNode *fast = head;

        // Considering the node itself can be a nullptr.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 慢指针走一步
            fast = fast->next->next;    // 快指针走两步

            // Has cycle if the ptrs meet.
            if (slow == fast) {
                return true;
            }
        }

        // Don't have cycle if meets nullptr
        return false;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool tryStep(ListNode *&node)
//     {
//         if (node == nullptr || node->next == nullptr)
//         // Considering the node itself being a nullptr.
//             return false;
//         node = node->next;
//         return true;
//     }

//     bool hasCycle(ListNode *head)
//     {
//         ListNode *fast = head, *slow = head;
//         while (true)
//         {
//             bool flag = false;
//             flag = (!tryStep(fast)) || (!tryStep(fast)) || (!tryStep(slow));
//             // Check if there is an end.
//             if (flag == true)
//                 return false;
//             if (fast == slow)
//                 return true;
//         }
//     }
// };

/* Reflection
 * Using nesting ptrs may induce boundary errors.
 * So just write inside the while loop.
*/