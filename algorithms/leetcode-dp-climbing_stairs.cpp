/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        int prev2 = 1, prev1 = 1;

        for (int i = 2; i <= n; i++)
        {
            int current=prev1+prev2;
            prev2=prev1;
            prev1=current;
        }

        return prev1;
    }
};
// @lc code=end

int main()
{
    int n = 3;
    auto result = Solution().climbStairs(n);
}