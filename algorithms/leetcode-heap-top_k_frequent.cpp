/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
        }

        using Frequency = pair<int, int>;
        priority_queue<Frequency, vector<Frequency>, greater<Frequency>> pq;

        for (const auto &frequency : count)
        {
            pq.push({frequency.second, frequency.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
// @lc code=end
