/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void siftUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent])
                break;

            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(int index)
    {
        int size = heap.size();

        while (2 * index + 1 < size)
        {
            int left = 2 * index + 1, right = 2 * index + 2;
            int smallest = (right < size && heap[right] < heap[left]) ? right : left;

            if (heap[smallest] >= heap[index])
                break;

            swap(heap[smallest], heap[index]);
            index = smallest;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    bool pop()
    {
        if (heap.empty())
            return false;

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        siftDown(0);
        return true;
    }

    int top()
    {
        return heap[0];
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        MinHeap pq;

        for (auto node : lists)
        {
            auto ptr = node;
            while (ptr != nullptr)
            {
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }

        ListNode *dummy = new ListNode(), *node = dummy;
        while (!pq.isEmpty())
        {
            int val = pq.top();
            pq.pop();
            node->next = new ListNode(val);
            node = node->next;
        }

        auto result = dummy->next;
        delete dummy;
        return result;
    }
};
// @lc code=end

// Better solution provided by Gemini:

#include <queue>
#include <vector>

class Solution {
public:
    // Min-heap comparison
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // PQ holds node pointers, capacity O(K)
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;

        // 1. Push all heads into PQ
        for (auto head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy(0); // Dummy node on stack
        ListNode* tail = &dummy;

        // 2. Extract min and append to result
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest; // Reuse existing node
            tail = tail->next;

            // 3. Push successor into PQ
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};