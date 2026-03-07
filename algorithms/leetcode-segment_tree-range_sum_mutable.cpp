/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include <vector>
using namespace std;

class NumArray
{
private:
    vector<int> tree;
    int n;

    void pushUp(int index)
    {
        tree[index] = tree[index << 1] + tree[index << 1 | 1];
    }

    void build(const vector<int> &nums, int index, int begin, int end)
    {
        if (begin == end)
        {
            tree[index] = nums[begin];
            return;
        }

        int mid = (end + begin) >> 1;
        int left = index << 1, right = index << 1 | 1;
        build(nums, left, begin, mid);
        build(nums, right, mid + 1, end);
        pushUp(index);
    }

    void update(int index, int begin, int end, int change, int val)
    {
        if (begin == end)
        {
            tree[index] = val;
            return;
        }

        int mid = (end + begin) >> 1;
        int left = index << 1, right = index << 1 | 1;
        if (change <= mid)
            update(left, begin, mid, change, val);
        else
            update(right, mid + 1, end, change, val);

        pushUp(index);
    }

    int query(int index, int begin, int end, int l, int r)
    {
        if (begin >= l && end <= r)
            return tree[index];

        int sum = 0;
        int mid = (end + begin) >> 1;
        int left = index << 1, right = index << 1 | 1;
        if (l <= mid)
            sum += query(left, begin, mid, l, r);
        if (mid < r)
            sum += query(right, mid + 1, end, l, r);
        return sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        tree = vector<int>(n * 4, 0);

        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val)
    {
        update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
