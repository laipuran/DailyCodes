/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 *
 * [1392] 最长快乐前缀
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> fail(n);

        for (int i = 1; i < n; i++)
        {
            int j = fail[i - 1];
            while (j > 0 && s[j] != s[i])
                j = fail[j - 1];
            if (s[i] == s[j])
                j++;
            fail[i] = j;
        }
        return s.substr(0,fail[n-1]);
    }
};
// @lc code=end
