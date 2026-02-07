/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution
{
private:
    // Swap two elements in the vector
    void swap(std::vector<int> &nums, int a, int b)
    {
        std::swap(nums[a], nums[b]);
    }

    // QuickSelect algorithm to find the kth smallest element
    int quickSelect(vector<int> &nums, int begin, int end, int k)
    {
        // 3-way partition to handle duplicates
        int pivot = nums[begin + rand() % (end - begin)];
        int lt = begin, gt = end - 1, i = begin;

        while (i <= gt)
        {
            if (nums[i] < pivot)
            {
                swap(nums, i, lt);
                i++;
                lt++;
            }
            else if (nums[i] > pivot)
            {
                swap(nums, i, gt);
                gt--;
            }
            else
            {
                i++;
            }
        }

        int leftLen = lt - begin;
        if (k <= leftLen)
            return quickSelect(nums, begin, lt, k);
        else if (k <= leftLen + (gt - lt + 1))
            return pivot;
        else
            return quickSelect(nums, gt + 1, end, k - (gt - begin + 1));
    }

public:
    // Find the kth largest element in the array
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(nullptr)); // Seed random number generator
        return quickSelect(nums, 0, nums.size(), nums.size() - k + 1);
    }
};
// @lc code=end
