// Luogu P1996 约瑟夫问题

#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    Node *head = new Node(1), *ptr = head;
    for (int i = 2; i <= n; i++)
    {
        ptr->next = new Node(i);
        ptr = ptr->next;
    }
    ptr->next = head;
    auto pri = ptr;
    ptr = head;

    while (ptr->next != ptr)
    {
        for (int i = 0; i < m - 1; i++)
        {
            pri = ptr;
            ptr = ptr->next;
        }
        pri->next = ptr->next;
        std::cout << ptr->val << " ";
        delete ptr;
        ptr = pri->next;
    }
    std::cout << ptr->val;
}