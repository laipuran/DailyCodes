/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
private:
    int *steps;

public:
    ~Solution()
    {
        delete[] steps;
    }

    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        steps = new int[n + 1];
        steps[0] = steps[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }

        return steps[n];
    }
};
// @lc code=end

int main()
{
    int n = 3;
    auto result = Solution().climbStairs(n);
}