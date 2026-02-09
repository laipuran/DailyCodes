/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// @lc code=start
#include <cmath>
#include <iostream>

class Solution
{
private:
public:
    Node *copyRandomList(Node *head)
    {
        Node *node = head;
        Node *dummy = new Node(0), *ptr = dummy;

        while (node != nullptr)
        {
            ptr->next = new Node(node->val);

            ptr = ptr->next;
            node = node->next;
        }

        node = head, ptr = dummy->next;
        while (node != nullptr)
        {
            if (node->random == nullptr)
                ptr->random = nullptr;
            else
            {
                auto temp = head, tempNew = dummy->next;

                while (temp != node->random)
                {
                    temp = temp->next;
                    tempNew = tempNew->next;
                }

                ptr->random = tempNew;
            }
            node = node->next;
            ptr = ptr->next;
        }

        auto newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
// @lc code=end

// Solution provided by Gemini
/*
The interweaving approach:
1. Copy nodes: Create A' for each node A and insert it after A (A -> A' -> B -> B').
2. Link random pointers: A'->random = A->random->next.
3. Decouple lists: Restore A -> B and extract A' -> B'.
This yields O(N) time and O(1) auxiliary space.
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        // 1. Interweave nodes
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // 2. Set random pointers
        curr = head;
        while (curr != nullptr)
        {
            if (curr->random != nullptr)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 3. Separate the lists
        Node *dummy = new Node(0);
        Node *copyCurr = dummy;
        curr = head;
        while (curr != nullptr)
        {
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }

        Node *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

int main()
{
    Node node0(7);
    Node node1(13);
    Node node2(11);
    Node node3(10);
    Node node4(1);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node1.random = &node0;
    node2.random = &node4;
    node3.random = &node2;
    node4.random = &node0;

    auto result = Solution().copyRandomList(&node0);
}