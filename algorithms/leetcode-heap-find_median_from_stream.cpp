/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <queue>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>, less<int>> minHeap;
    int count = 0;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        count++;
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
