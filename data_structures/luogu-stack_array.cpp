// Luogu B3614

#include <iostream>
using namespace std;

unsigned long long st[1000001];
class Stack
{
private:
    int index;

public:
    Stack() : index(-1) {}
    void push(long long x)
    {
        index++;
        st[index] = x;
    }
    bool pop()
    {
        if (index == -1)
            return false;
        index--;
        return true;
    }
    const unsigned long long *query() const
    {
        if (index == -1)
            return nullptr;
        return &st[index];
    }
    int size()
    {
        return index + 1;
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