/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <vector>
#include <cstdlib>
using namespace std;

// Merge Sort
class Solution
{
private:
    void mergeSort(vector<int> &nums, int begin, int end)
    {
        if (end - begin <= 1)
            return;

        // The index of the right part
        int mid = begin + (end - begin) / 2;

        mergeSort(nums, begin, mid);
        mergeSort(nums, mid, end);

        vector<int> temp;
        int left = begin, right = mid;

        while (left < mid && right < end)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        // Fill after comparison.
        while (left < mid)
            temp.push_back(nums[left++]);
        while (right < end)
            temp.push_back(nums[right++]);

        for (int i = 0; i < temp.size(); i++)
        {
            nums[begin + i] = temp[i];
        }
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size());
        return nums;
    }
};
// @lc code=end

// Quick Sort
class Solution
{
private:
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void quickSort(vector<int> &nums, int begin, int end)
    {
        // Interval: [begin, end) -> standard C++ iterator style (exclusive end)
        if (end - begin <= 1)
            return;

        // Optimized Pivot Selection:
        // Using a fixed index (like 'begin') causes O(N^2) performance on sorted arrays.
        // Randomly selecting a pivot breaks this pattern.
        int randomIndex = begin + rand() % (end - begin);
        swap(nums, begin, randomIndex);

        // Now valid to use the element at 'begin' as pivot
        int pivotVal = nums[begin];

        // Pointers setup:
        // left: starts at begin + 1
        // right: starts at end - 1 (last valid index)
        int left = begin + 1, right = end - 1;

        // Use 'left <= right' to include the meeting element in the check.
        // If we use 'left < right', the element where they meet is skipped
        // and might be swapped incorrectly.
        while (left <= right)
        {
            // Move left forward if element is smaller than pivot
            while (left <= right && nums[left] < pivotVal)
                left++;
            // Move right backward if element is larger than pivot
            while (left <= right && nums[right] > pivotVal)
                right--;

            // If indices are valid, swap and move both
            if (left <= right)
            {
                swap(nums, left, right);
                left++;
                right--;
            }
        }

        // Swap pivot with 'right'.
        // Why 'right'? Because at the end of loop, 'right' points to
        // the last element that is <= pivotVal (since we decrement right when > pivot).
        // This partition ensures pivot is placed between smaller and larger elements.
        swap(nums, begin, right);

        // Recursive calls:
        // Left part: [begin, right)
        // 'right' is the index of the pivot now. We exclude it.
        quickSort(nums, begin, right);

        // Right part: [left, end)
        // We start after the pivot index. 'end' remains the same exclusive bound.
        quickSort(nums, left, end);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size());
        return nums;
    }
};