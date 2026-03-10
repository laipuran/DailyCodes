/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        bool used[128];
        int max = 0;
        for (int i = 0; i < 128; i++)
            used[i] = false;
        for (int i = 0; i < s.length(); i++)
        {
            int count = 0;
            for (int j = i; j < s.length(); j++)
            {
                if (used[s[j]] == true)
                    break;
                used[s[j]] = true;
                count++;
            }
            max = count > max ? count : max;

            for (int i = 0; i < 128; i++)
                used[i] = false;
        }
        return max;
    }
};
// @lc code=end

// A worse solution provided by myself

class Solution
{
private:
    bool used[128];
    int max = 0;
    int backtracking(const string &s, int index)
    {
        if (index >= s.length())
            return 0;
        if (used[s[index]])
            return 0;

        used[s[index]] = true;
        int after = backtracking(s, index + 1);
        used[s[index]] = false;
        return 1 + after;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        for (int i = 0; i < 128; i++)
            used[i] = false;

        for (int i = 0; i < s.length(); i++)
        {
            int count = backtracking(s, i);
            max = count > max ? count : max;
        }
        return max;
    }
};