/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> chosen;

    void backtracking(const vector<int> &nums, int n, int index)
    {
        if (n == 0)
        {
            result.push_back(chosen);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            chosen.push_back(nums[i]);
            backtracking(nums, n - 1, i + 1);
            chosen.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++)
            backtracking(nums, i, 0);
        return result;
    }
};
// @lc code=end
