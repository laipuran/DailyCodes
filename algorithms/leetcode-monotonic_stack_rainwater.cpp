/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include<iostream>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> index;
        int n = height.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            while (!index.empty() && height[i] > height[index.top()]) {
                int bottom = height[index.top()];
                index.pop();
                if (index.empty()) break;
                int right = height[i];
                int left = height[index.top()];
                int h = min(right, left) - bottom;
                int w = i - index.top() - 1;
                sum += h * w;
            }
            index.push(i);
        }
        return sum;
    }
};
// @lc code=end

