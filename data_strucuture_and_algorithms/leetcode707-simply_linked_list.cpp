struct Node
{
    int value;
    Node *nextNode;
    Node(int val) : value(val), nextNode(nullptr) {}
};

class MyLinkedList
{
private:
    Node *head;
    int length;

public:
    MyLinkedList()
    {
        head = nullptr; // Initialize as nullptr.
        length = 0;
    }

    ~MyLinkedList()
    {
        Node *current = head;
        for (int i = 0; i < length; i++)
        {
            Node *del = current;
            current = del->nextNode;
            delete del;
        }
    }

    Node *getNode(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->nextNode;
        }
        return current;
    }

    int get(int index)
    {
        Node *node = getNode(index);
        if (node == nullptr)
            return -1; // Remember to change on other situations.
        else
            return node->value;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val);
        node->nextNode = head;
        head = node;
        length++;
    }

    void addAtTail(int val)
    {
        if (length == 0)
        {
            head = new Node(val);
        }
        else
        {
            Node *node = new Node(val);
            getNode(length - 1)->nextNode = node;
        }
        length++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > length)
            return;
        if (index == length)
            addAtTail(val);
        else if (index == 0)
            addAtHead(val);
        else
        {
            Node *node = getNode(index - 1);
            Node *newNode = new Node(val);
            newNode->nextNode = node->nextNode;
            node->nextNode = newNode;
            length++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (index == 0)
        {
            Node *node = head;
            head = head->nextNode;
            delete node;
        }
        else
        {
            Node *node = getNode(index - 1);
            Node *del = node->nextNode;
            node->nextNode = del->nextNode;
            delete del;
        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */