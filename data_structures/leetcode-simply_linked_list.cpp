/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
struct Node
{
    int value;
    Node *nextNode;
    Node(int val) : value(val), nextNode(nullptr) {}
    Node(int val, Node *next) : value(val), nextNode(next) {}
};

class MyLinkedList
{
private:
    Node *dummyHead;
    int length;

public:
    MyLinkedList()
    {
        dummyHead = new Node(0);
        length = 0;
    }

    ~MyLinkedList()
    {
        Node *current = dummyHead;
        for (int i = 0; i <= length; i++)
        {
            Node *del = current;
            current = del->nextNode;
            delete del;
        }
    }

    Node *getNode(int index)
    {
        if (index < -1 || index >= length)
            return nullptr;
        Node *current = dummyHead;
        for (int i = -1; i < index; i++)
        {
            current = current->nextNode;
        }
        return current;
    }

    int get(int index)
    {
        Node *node = getNode(index);
        return (node == nullptr || index == -1) ? -1 : node->value;
        // Remember to change -1 to other value in other situattions.
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(length, val); // Reuse current logic.
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > length)
            return;
        else
        {
            Node *node = getNode(index - 1);
            Node *newNode = new Node(val, node->nextNode);
            // If length equals 0, newNode->nextNode would be pointing to nullptr.
            node->nextNode = newNode;
            length++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;

        Node *node = getNode(index - 1);
        Node *del = node->nextNode;
        node->nextNode = del->nextNode;
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
// @lc code=end

