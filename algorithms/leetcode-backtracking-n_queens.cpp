/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
#include<cmath>
using namespace std;

class Solution
{
    // Line and column number start at 0.
    int n;
    vector<vector<string>> result;
    vector<int> columnPath;

    void build()
    {
        vector<string> map;
        for (int column : columnPath)
        {
            string str = string(n, '.');
            str[column] = 'Q';
            map.push_back(str);
        }
        result.push_back(map);
    }

    bool isValid(int column)
    {
        for (int i = 0; i < columnPath.size(); i++)
        {
            if (columnPath[i] == column)
                return false;

            if (abs(column - columnPath[i])==abs((int)columnPath.size() - i))
                return false;
        }
        return true;
    }

    void backtracking(int lineIndex)
    {
        if (columnPath.size() == n)
        {
            build();
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!isValid(i))
                continue;

            columnPath.push_back(i);
            backtracking(lineIndex + 1);
            columnPath.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        backtracking(0);
        return result;
    }
};
// @lc code=end

int main()
{
    auto result = Solution().solveNQueens(4);
}