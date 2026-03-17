/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.length();
        vector<int> next(n);

        next[0] = 0;
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (needle[i] == needle[j])
            {
                j++;
            }

            next[i] = j;
        }

        j = 0;
        for (int i = 0; i < haystack.length(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                j++;
            }

            if (j == n)
            {
                return i - n + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
