// Luogu B3616

#include <iostream>

using namespace std;

struct Node
{
    unsigned int value;
    Node *next;
    Node(unsigned int val) : value(val), next(nullptr) {}
    Node(unsigned int val, Node *next) : value(val), next(next) {}
};

class Queue
{
private:
    Node *dummy;
    Node *tail;
    int capacity;

public:
    Queue()
    {
        dummy = new Node(0);
        tail = dummy;
        capacity = 0;
    }
    void push(unsigned int x)
    {
        Node *newNode = new Node(x);
        tail->next = newNode;
        tail = newNode;
        capacity++;
    }
    bool pop()
    {
        if (capacity == 0)
            return false;
        auto del = dummy->next;
        dummy->next = del->next;
        // When del is the last node, it causes segmentation fault.
        if (del == tail)
            tail = dummy;
        delete del;
        capacity--;
        return true;
    }
    const unsigned int *query() const
    {
        if (capacity == 0)
            return nullptr;
        return &dummy->next->value;
    }
    int size() const
    {
        return capacity;
    }
    ~Queue()
    {
        while (query())
            pop();
        delete dummy;
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int times;
    cin >> times;

    Queue queue;

    for (int i = 0; i < times; i++)
    {
        int operation;
        cin >> operation;
        switch (operation)
        {
        case 1:
        {
            unsigned int num;
            cin >> num;
            queue.push(num);
            break;
        }
        case 2:
        {
            auto flag = queue.pop();
            if (!flag)
                cout << "ERR_CANNOT_POP\n";
            break;
        }
        case 3:
        {
            auto ptr = queue.query();
            if (ptr == nullptr)
                cout << "ERR_CANNOT_QUERY\n";
            else
                cout << *ptr << "\n";
            break;
        }
        case 4:
        {
            cout << queue.size() << "\n";
            break;
        }
        default:
            break;
        }
    }
}