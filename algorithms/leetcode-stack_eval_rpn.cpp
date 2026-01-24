/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> numbers;
        for (int i = 0; i < tokens.size(); i++)
        {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                switch (token[0])
                {
                case '+':
                    numbers.push(a + b);
                    break;
                case '-':
                    numbers.push(a - b);
                    break;
                case '*':
                    numbers.push(a * b);
                    break;
                case '/':
                    numbers.push(a / b);
                    break;
                default:
                    break;
                }
            }
            else numbers.push(stoi(token));
        }
        return numbers.top();
    }
};
// @lc code=end
