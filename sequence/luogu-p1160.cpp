// Luogu P1160 队列安排

#include <iostream>
#include <vector>

struct Node
{
    int val;
    Node *next, *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

Node *insert_at_right(Node *node, int val)
{
    Node *n = new Node(val);
    n->next = node->next;
    n->next->prev = n;
    node->next = n;
    n->prev = node;
    return n;
}

void remove(Node *node)
{
    if (node == nullptr)
        return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

int main()
{
    Node *head = new Node(), *tail = new Node();
    tail->next = head->prev = nullptr;
    head->next = tail, tail->prev = head;
    int n, m;
    std::cin >> n;
    std::vector<Node *> ptrs(n + 1);
    ptrs[1] = insert_at_right(head, 1);
    for (int i = 2; i <= n; i++)
    {
        int idx, pos;
        std::cin >> idx >> pos;
        ptrs[i] = pos == 0 ? insert_at_right(ptrs[idx]->prev, i)
                           : insert_at_right(ptrs[idx], i);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int idx;
        std::cin >> idx;
        remove(ptrs[idx]);
        ptrs[idx] = nullptr;
    }
    auto ptr = head->next;
    while (ptr != nullptr && ptr->val != 0)
    {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
}