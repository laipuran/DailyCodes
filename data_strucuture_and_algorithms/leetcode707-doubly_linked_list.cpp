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
    Node *head;
    Node *tail;
    int length;

public:
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr; // Initialize as nullptr.
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

        Node *current = nullptr;
        if (index <= length / 2)
        {
            current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->nextNode;
            }
        }
        else
        {
            current = tail;
            for (int i = length - 1; i > index; i--)
            {
                current = current->previousNode;
            }
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
        if (head != nullptr)
            head->previousNode = node;
        node->nextNode = head;
        head = node;
        if (length == 0)
            tail = head;
        length++;
    }

    void addAtTail(int val)
    {
        if (length == 0)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *node = new Node(val);
            node->previousNode = tail;
            tail->nextNode = node;
            tail = node;
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
            newNode->previousNode = node;
            node->nextNode = newNode;
            newNode->nextNode->previousNode = newNode;
            length++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (index == 0)
        {
            if (length == 0)
                tail = nullptr;
            Node *node = head;
            head = head->nextNode;
            delete node;
        }
        else if (index == length - 1)
        {
            Node *del = tail;
            Node *node = tail->previousNode;
            node->nextNode = nullptr;
            tail = node;
            delete del;
        }
        else
        {
            Node *node = getNode(index - 1);
            Node *del = node->nextNode;
            del->nextNode->previousNode = node;
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