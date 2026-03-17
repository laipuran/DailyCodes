/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int left = target - nums[i];
            if (map.count(left) != 0)
                return {i, map[left]};
            else
                map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

// Using two pointers:

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size();
        std::vector<std::pair<int, int>> pairs;
        for (int i = 0; i < n; i++)
            pairs.push_back({nums[i], i});

        std::sort(pairs.begin(), pairs.end());
        int j = n - 1;
        for (int i = 0; i < j; i++)
        {
            int left = target - pairs[i].first;
            while (pairs[j].first > left)
                j--;
            if (pairs[j].first == left)
                return {pairs[i].second, pairs[j].second};
        }
        return {};
    }
};
