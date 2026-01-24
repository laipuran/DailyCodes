/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> pings;

public:
    RecentCounter() {}

    int ping(int t)
    {
        pings.push(t);
        while (pings.front() < t - 3000)
            pings.pop();
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
