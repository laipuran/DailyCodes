/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> next;
    bool isEnd;

    TrieNode() : next(unordered_map<char, TrieNode *>()), isEnd(false) {};
};

class Trie
{
private:
    TrieNode *head;

public:
    Trie()
    {
        head = new TrieNode();
    }

    void insert(string word)
    {
        auto ptr = head;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (ptr->next.count(ch) == 0)
            {
                ptr->next[ch] = new TrieNode();
            }
            ptr = ptr->next[ch];
        }
        ptr->isEnd = true;
    }

    bool search(string word)
    {
        auto ptr = head;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (ptr->next.count(ch) == 0 || ptr->next.find(ch) == ptr->next.end())
                return false;

            ptr = ptr->next[ch];
        }
        return ptr->isEnd;
    }

    bool startsWith(string prefix)
    {
        auto ptr = head;
        for (int i = 0; i < prefix.length(); i++)
        {
            char ch = prefix[i];

            if (ptr->next.count(ch) == 0 || ptr->next.find(ch) == ptr->next.end())
                return false;

            ptr = ptr->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main()
{

    Trie *obj = new Trie();
    string word = "hello";
    string prefix = "hell";

    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
}
