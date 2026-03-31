/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution
{
private:
    int priority(char ch)
    {
        if (ch == '+' || ch == '-')
            return 0;
        if (ch == '*' || ch == '/')
            return 1;
        return -1;
    }

public:
    int calculate(string s)
    {
        s += "+0";
        stack<char> ops;
        stack<int> nums;

        int temp = 0;
        for (char ch : s)
        {
            if (ch == ' ')
                continue;
            if (isdigit(ch))
                temp = temp * 10 + (ch - '0');
            else
            {
                nums.push(temp);
                temp = 0;
                while (!ops.empty() && priority(ch) <= priority(ops.top()))
                {
                    int num = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();

                    switch (op)
                    {
                    case '+':
                        nums.top() += num;
                        break;
                    case '-':
                        nums.top() -= num;
                        break;
                    case '*':
                        nums.top() *= num;
                        break;
                    case '/':
                        nums.top() /= num;
                        break;
                    default:
                        break;
                    }
                }
                ops.push(ch);
            }
        }
        int result;
        while (!nums.empty())
        {
            result = nums.top();
            nums.pop();
        }
        return result;
    }
};
// @lc code=end

int main()
{
    string str = "3+2*2";
    int result = Solution().calculate(str);
}