/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

struct TrieNode
{
    bool isEnd;
    unordered_map<char, TrieNode *> next;

    TrieNode() : isEnd(false) {}
};

class Dictionary
{
private:
    TrieNode *dummy;

public:
    Dictionary()
    {
        dummy = new TrieNode();
    }

    void insert(string word)
    {
        auto node = dummy;
        for (auto ch : word)
        {
            if (node->next.count(ch) == 0)
            {
                auto next = node->next[ch] = new TrieNode();
            }
            node = node->next[ch];
        }
        node->isEnd = true;
    }

    string getPrefix(string word)
    {
        auto node = dummy;
        string prefix = "";
        for (auto ch : word)
        {
            if (node->next.count(ch) == 0)
                break;
            node = node->next[ch];
            prefix += ch;

            // Make sure the shortest path
            if (node->isEnd)
                return prefix;
        }
        return word;
    }
};

class Solution
{
private:
    Dictionary dic;

    void buildTree(const vector<string> &dictionary)
    {
        for (auto word : dictionary)
        {
            dic.insert(word);
        }
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        buildTree(dictionary);

        stringstream ss(sentence);
        string word, res = "";

        while (ss >> word)
        {
            if (!res.empty())
                res += " ";
            res += dic.getPrefix(word);
        }

        return res;
    }
};
// @lc code=end
