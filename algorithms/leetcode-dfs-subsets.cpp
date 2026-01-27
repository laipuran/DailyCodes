/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> numbers;
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int index)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        for (int i = index; i < n - (k - path.size()) + 1; i++)
        {
            path.push_back(numbers[i]);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        numbers = nums;
        for (int i = 0; i <= nums.size(); i++)
            backtracking(nums.size(), i, 0);
        return result;
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    auto result = Solution().subsets(nums);
}