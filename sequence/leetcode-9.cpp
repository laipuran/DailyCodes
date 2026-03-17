/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Be aware of the sign
        if (x < 0)
            return false;
        
        std::vector<int> digits;

        while (x != 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }

        int n = digits.size();
        for (int i = 0; i < n / 2; i++)
            if (digits[i] != digits[n - 1 - i])
                return false;
        return true;
    }
};
// @lc code=end

// Convert the number to string:

#include <string>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string str = std::to_string(x);
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            if (str[i] != str[n - 1 - i])
                return false;
        return true;
    }
};