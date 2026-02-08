/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap
{
private:
    const int base = 769;

    struct Node
    {
        int key;
        int val;
        Node *next;

        Node(int key, int val) : key(key), val(val), next(nullptr) {}
    };

    Node *map[769];

    int getHash(int key) { return key % base; }

public:
    MyHashMap()
    {
        for (int i = 0; i < base; i++)
            map[i] = nullptr;
    }

    ~MyHashMap()
    {
        for (int i = 0; i < base; ++i)
        {
            Node *current = map[i];
            while (current != nullptr)
            {
                Node *next = current->next;
                delete current;
                current = next;
            }
            map[i] = nullptr;
        }
    }

    MyHashMap(const MyHashMap &) = delete;
    MyHashMap &operator=(const MyHashMap &) = delete;
    void put(int key, int value)
    {
        const int hash = getHash(key);

        if (map[hash] == nullptr)
        {
            map[hash] = new Node(key, value);
            return;
        }

        Node *current = map[hash];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->val = value;
                return;
            }

            if (current->next == nullptr)
                break;

            current = current->next;
        }

        current->next = new Node(key, value);
    }

    int get(int key)
    {
        const int hash = getHash(key);

        Node *current = map[hash];

        while (current != nullptr)
        {
            if (current->key == key)
                return current->val;
            current = current->next;
        }

        return -1;
    }

    void remove(int key)
    {
        const int hash = getHash(key);

        Node *current = map[hash];

        if (current == nullptr)
            return;

        if (current->key == key)
        {
            map[hash] = current->next;
            delete current;
            return;
        }

        while (current->next != nullptr)
        {
            if (current->next->key == key)
            {
                auto next = current->next;
                current->next = next->next;
                delete next;
                return;
            }
            current = current->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
