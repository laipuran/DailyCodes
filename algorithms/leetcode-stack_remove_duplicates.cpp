/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> chars;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!chars.empty() && chars.top() == s[i])
            {
                chars.pop();
                continue;
            }
            chars.push(s[i]);
        }
        string out;
        while(!chars.empty()){
            out+=chars.top();
            chars.pop();
        }
        return out;
    }
};
// @lc code=end
