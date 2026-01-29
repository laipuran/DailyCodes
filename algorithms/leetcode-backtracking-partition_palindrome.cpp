/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    string str;
    vector<vector<string>> result;
    vector<string> split;

    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - i - 1])
                return false;
        return true;
    }

    bool equals()
    {
        int sum = 0;
        for (string item : split)
            sum += item.length();
        return sum == str.length();
    }

    void backtracking(int index)
    {
        if (equals())
        {
            result.push_back(split);
            return;
        }

        for (int i = index; i < str.length(); i++)
        {
            string temp = str.substr(index, i - index + 1);
            if (!isPalindrome(temp))
                continue;
            split.push_back(temp);
            backtracking(i + 1);
            split.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        str = s;
        backtracking(0);
        return result;
    }
};
// @lc code=end
