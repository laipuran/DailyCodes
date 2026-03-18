/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        int i = m + n - 1, j = m - 1, k = n - 1;

        // Compare & add at tail to stay easy
        while (k >= 0 && j >= 0)
        {
            if (nums1[j] > nums2[k])
            {
                nums1[i] = nums1[j];
                i--;
                j--;
            }
            else
            {
                nums1[i] = nums2[k];
                i--;
                k--;
            }
        }

        while (k >= 0)
        {
            nums1[i] = nums2[k];
            i--;
            k--;
        }
    }
};
// @lc code=end
