/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
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

class WordDictionary
{
private:
    TrieNode *head;

    bool backtracking(const string &option, int index, TrieNode *node)
    {
        if (index == option.length() && node->isEnd == true)
            return true;

        char ch = option[index];
        if (ch == '.')
        {
            for (auto const &[key, childNode] : node->next)
            {
                if (backtracking(option, index + 1, childNode))
                {
                    return true;
                }
            }
        }
        else if (node->next.count(ch))
        {
            return backtracking(option, index + 1, node->next[ch]);
        }
        return false;
    }

public:
    WordDictionary()
    {
        head = new TrieNode();
    }

    void addWord(string word)
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
        return backtracking(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
