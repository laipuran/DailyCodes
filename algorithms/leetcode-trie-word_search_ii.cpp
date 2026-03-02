/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

struct TrieNode
{
    bool isEnd;
    unordered_map<char, TrieNode *> next;
    TrieNode() : isEnd(false) {}
};

class Dictionary
{
public:
    TrieNode dummy;

    void insert(const string &word)
    {
        auto node = &dummy;
        for (auto ch : word)
        {
            if (node->next.find(ch) == node->next.end())
                node->next[ch] = new TrieNode();
            node = node->next[ch];
        }
        node->isEnd = true;
    }
};

class Solution
{
private:
    vector<char> path;
    set<string> result;
    vector<vector<bool>> used;

    void backtracking(const vector<vector<char>> &board, TrieNode *node, int ln, int col)
    {
        if (node->isEnd)
        {
            result.insert(string(path.begin(), path.end()));
        }

        static int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < 4; i++)
        {
            int y = ln + delta[i][0];
            int x = col + delta[i][1];

            if (y >= 0 && y < m && x >= 0 && x < n && !used[y][x])
            {
                char nextChar = board[y][x];
                auto it = node->next.find(nextChar);
                if (it != node->next.end())
                {
                    path.push_back(nextChar);
                    used[y][x] = true;
                    backtracking(board, it->second, y, x);
                    used[y][x] = false;
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Dictionary dic;
        for (const string &word : words)
        {
            dic.insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        used = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char startChar = board[i][j];
                auto it = dic.dummy.next.find(startChar);
                if (it != dic.dummy.next.end())
                {
                    path.push_back(startChar);
                    used[i][j] = true;
                    backtracking(board, it->second, i, j);
                    used[i][j] = false;
                    path.pop_back();
                }
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};
// @lc code=end

// // A better solution provided by Gemini
// #include <vector>
// #include <string>

// using namespace std;

// struct TrieNode
// {
//     string *word;
//     TrieNode *next[26];
//     TrieNode() : word(nullptr)
//     {
//         for (int i = 0; i < 26; i++)
//             next[i] = nullptr;
//     }
// };

// class Solution
// {
// private:
//     void insert(TrieNode *root, string &s)
//     {
//         TrieNode *node = root;
//         for (char c : s)
//         {
//             int idx = c - 'a';
//             if (!node->next[idx])
//                 node->next[idx] = new TrieNode();
//             node = node->next[idx];
//         }
//         node->word = &s;
//     }

//     void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node, vector<string> &result)
//     {
//         char temp = board[r][c];
//         int idx = temp - 'a';

//         if (temp == '#' || !node->next[idx])
//             return;

//         node = node->next[idx];
//         if (node->word)
//         {
//             result.push_back(*(node->word));
//             node->word = nullptr; // avoid duplicate results
//         }

//         board[r][c] = '#'; // mark as visited

//         if (r > 0)
//             dfs(board, r - 1, c, node, result);
//         if (c > 0)
//             dfs(board, r, c - 1, node, result);
//         if (r < board.size() - 1)
//             dfs(board, r + 1, c, node, result);
//         if (c < board[0].size() - 1)
//             dfs(board, r, c + 1, node, result);

//         board[r][c] = temp; // backtrack
//     }

// public:
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
//     {
//         TrieNode *root = new TrieNode();
//         for (string &w : words)
//             insert(root, w);

//         vector<string> result;
//         int m = board.size();
//         int n = board[0].size();

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 dfs(board, i, j, root, result);
//             }
//         }

//         return result;
//     }
// };