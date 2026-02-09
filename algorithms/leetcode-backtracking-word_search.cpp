/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    bool **used;
    int status = 0;

    bool backtracking(vector<vector<char>> &board, string word, int ln, int col)
    {
        if (status == word.length())
            return true;

        int totalLn = board.size();
        int totalCol = board[0].size();
        int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < 4; i++)
        {
            int nextLn = ln + delta[i][0];
            int nextCol = col + delta[i][1];
            if (nextLn < 0 || nextLn >= totalLn || nextCol < 0 || nextCol >= totalCol)
                continue;
                
            if (board[nextLn][nextCol] != word[status])
                continue;

            if (used[nextLn][nextCol] == true)
                continue;

            status++;
            used[nextLn][nextCol] = true;

            if (backtracking(board, word, nextLn, nextCol))
            {
                return true;
            }

            used[nextLn][nextCol] = false;
            status--;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int totalLn = board.size();
        int totalCol = board[0].size();

        used = new bool *[totalLn];
        for (int i = 0; i < totalLn; i++)
        {
            used[i] = new bool[totalCol];
            for (int j = 0; j < totalCol; j++)
                used[i][j] = false;
        }

        for (int i = 0; i < totalLn; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                used[i][j] = true;
                status++;
                if (board[i][j] == word[0] && backtracking(board, word, i, j))
                    return true;
                status--;
                used[i][j] = false;
            }
        }
        return false;
    }
};
// @lc code=end
