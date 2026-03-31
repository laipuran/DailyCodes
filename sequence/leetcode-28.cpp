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
private:
    vector<int> prefix(string s)
    {
        int n = s.length();
        vector<int> fail(n);
        for (int i = 1; i < n; i++)
        {
            int j = fail[i - 1];
            while (j > 0 && s[i] != s[j])
                j = fail[j - 1];
            if (s[i] == s[j])
                j++;
            fail[i] = j;
        }
        return fail;
    }

public:
    int strStr(string haystack, string needle)
    {
        auto pref = prefix(needle);
        int n = haystack.length(), m = needle.length();

        int i = 0, j = 0;
        for (; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = pref[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};
// @lc code=end
