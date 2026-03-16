/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <cmath>

using namespace std;

class Solution
{
private:
    int max = 0, n;
    string result, s;

    void expand(int left, int right)
    {
        while (true)
        {
            if (left < 0 || right >= n)
                break;
            if (s[left] != s[right])
                break;
            left--;
            right++;
        }
        left++;
        right--;
        int sum = right - left + 1;

        if (sum > max)
        {
            max = std::max(max, sum);
            result = s.substr(left, sum);
        }
    }

public:
    string longestPalindrome(string s)
    {
        Solution::s = s;
        n = s.length();

        for (int i = 0; i < n; i++)
        {
            expand(i, i);
            expand(i, i + 1);
        }
        return result;
    }
};
// @lc code=end

// DP solution provided by Gemini:
#include <vector>
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i <= n - L; i++)
            {
                int j = i + L - 1;

                if (s[i] == s[j])
                {
                    if (L <= 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && L > maxLen)
                {
                    maxLen = L;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// Manecher provided by Gemini:
class Solution {
public:
    string longestPalindrome(string s) {
        string T = "#";
        for (char c : s) {
            T += c;
            T += "#";
        }

        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        int maxLen = 0, centerIndex = 0;

        for (int i = 0; i < n; i++) {
            if (i < R) {
                int i_mirror = 2 * C - i;
                P[i] = min(R - i, P[i_mirror]);
            }

            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < n && T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};