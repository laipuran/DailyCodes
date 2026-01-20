struct Node
{
    int value;
    Node *previousNode;
    Node *nextNode;
    Node(int val) : value(val), previousNode(nullptr), nextNode(nullptr) {}
    Node(int val, Node *previous, Node *next) : value(val), previousNode(previous), nextNode(next) {}
};

class MyLinkedList
{
private:
    Node *dummyHead;
    Node *dummyTail;
    int length;

public:
    MyLinkedList()
    {
        dummyHead = new Node(0);
        dummyTail = new Node(0, dummyHead, nullptr);
        dummyHead->nextNode = dummyTail;
        length = 0;
    }

    ~MyLinkedList()
    {
        Node *current = dummyHead;
        for (int i = 0; i < length + 2; i++)
        {
            Node *del = current;
            current = del->nextNode;
            delete del;
        }
    }

    Node *getNode(int index)
    {
        if (index < -1 || index > length)
            return nullptr;

        Node *current = nullptr;
        if (index <= length / 2)
        {
            current = dummyHead;
            for (int i = -1; i < index; i++)
            {
                current = current->nextNode;
            }
        }
        else
        {
            current = dummyTail;
            for (int i = length; i > index; i--)
            {
                current = current->previousNode;
            }
        }
        return current;
    }

    int get(int index)
    {
        Node *node = getNode(index);
        return ((index < 0 || index >= length) || node == nullptr) ? -1 : node->value;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(length, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > length)
            return;

        Node *previousNode = getNode(index - 1);
        Node *nextNode = previousNode->nextNode;
        Node *newNode = new Node(val, previousNode, nextNode);
        previousNode->nextNode = newNode;
        nextNode->previousNode = newNode;
        length++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;

        Node *previousNode = getNode(index - 1);
        Node *nextNode = previousNode->nextNode->nextNode;
        Node *del = previousNode->nextNode;
        nextNode->previousNode = previousNode;
        previousNode->nextNode = nextNode;
        delete del;
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