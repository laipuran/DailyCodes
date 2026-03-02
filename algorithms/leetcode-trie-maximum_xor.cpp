/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
#include <vector>
#include <cmath>

using namespace std;

struct TrieNode
{
    TrieNode *next[2];
    TrieNode()
    {
        next[0] = next[1] = nullptr;
    }
};

class Trie
{
public:
    TrieNode dummy;

    void insert(int num)
    {
        auto node = &dummy;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->next[bit] == nullptr)
                node->next[bit] = new TrieNode();

            node = node->next[bit];
        }
    }
};

class Solution
{
private:
    Trie t;
    int getMaxXor(int num)
    {
        auto node = &t.dummy;
        int max_xor = 0;

        for (int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int target = 1 - bit;

            if (node->next[target] != nullptr)
            {
                max_xor |= (1 << i);
                node = node->next[target];
            }
            else
                node = node->next[bit];
        }

        return max_xor;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        for (auto num : nums)
            t.insert(num);

        int result = 0;
        for (auto num : nums)
            result = max(result, getMaxXor(num));

        return result;
    }
};
// @lc code=end
