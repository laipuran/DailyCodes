/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (char ch : s)
        {
            switch (ch)
            {
            case '(':
                brackets.push(')');
                break;
            case '[':
                brackets.push(']');
                break;
            case '{':
                brackets.push('}');
                break;

            case ')':
            case ']':
            case '}':
                if (brackets.empty() || brackets.top() != ch)
                    return false;
                brackets.pop();
            default:
                break;
            }
        }
        if (!brackets.empty())
            return false;
        return true;
    }
};
// @lc code=end
