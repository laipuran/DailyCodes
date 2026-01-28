/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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

    void backtracking(const vector<int> &numbers, int index, int sum, int target)
    {
        if (sum == target)
        {
            result.push_back(chosen);
            return;
        }

        for (int i = index; i < numbers.size(); i++)
        {
            if (sum + numbers[index] > target)
                break;
            chosen.push_back(numbers[i]);
            backtracking(numbers, i, sum + numbers[i], target);
            chosen.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target);
        return result;
    }
};
// @lc code=end
