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