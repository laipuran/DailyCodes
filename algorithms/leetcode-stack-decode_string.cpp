/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string number, token;
        stack<string> count;
        stack<string> strs;
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                string &ref = ('0' <= ch && ch <= '9') ? number : token;
                ref += ch;
            }
            else if (ch == '[')
            {
                strs.push(token);
                count.push(number);
                token = number = "";
            }
            else if (ch == ']')
            {
                int num = stoi(count.top());
                count.pop();
                string repeat;

                for (int i = 0; i < num; i++)
                    repeat += token;
                string base = strs.top();
                strs.pop();

                // Don't save to the stack.
                token = base + repeat;
                number = "";
            }
        }
        return token;
    }
};
// @lc code=end

#include <iostream>

int main()
{
    string str;
    cin >> str;
    Solution sln;

    cout << sln.decodeString(str);
}