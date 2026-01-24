// Luogu B3614

#include <iostream>
using namespace std;

struct Node
{
    unsigned long long value;
    // Be aware of the data type.
    Node *next;
    Node(unsigned long long val) : value(val), next(nullptr) {}
    Node(unsigned long long val, Node *next) : value(val), next(next) {}
};

class Stack
{
private:
    Node *dummy;
    Node *top;
    int capacity;

public:
    Stack()
    {
        capacity = 0;
        dummy = new Node(0);
        top = dummy;
    }
    void push(long long x)
    {
        Node *newNode = new Node(x, top);
        top = newNode;
        capacity++;
    }
    bool pop()
    {
        if (top == dummy)
            return false;
        auto del = top;
        top = top->next;
        delete del;
        capacity--;
        return true;
    }
    const unsigned long long *query() const
    {
        if (top == dummy)
            return nullptr;
        return &top->value;
    }
    int size() const
    {
        return capacity;
    }
    ~Stack()
    {
        while (this->query())
            pop();
        delete dummy;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int group;
    cin >> group;
    for (int i = 0; i < group; i++)
    {
        Stack stack;
        int times;
        cin >> times;
        for (int j = 0; j < times; j++)
        {
            string operation;
            cin >> operation;

            if (operation == "push")
            {
                unsigned long long num;
                cin >> num;
                stack.push(num);
            }
            else if (operation == "query")
            {
                auto ptr = stack.query();
                if (ptr == nullptr)
                    cout << "Anguei!\n";
                else
                    cout << *ptr << endl;
            }
            else if (operation == "pop")
            {
                bool flag = stack.pop();
                if (!flag)
                    cout << "Empty\n";
            }
            else if (operation == "size")
                cout << stack.size() << "\n";
        }
    }
}