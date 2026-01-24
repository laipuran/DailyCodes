/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> days = vector<int>(temperatures.size(), 0);
        stack<int> indexes;
        for(int i=0;i<temperatures.size();i++){
            while(!indexes.empty()&&temperatures[i]>temperatures[indexes.top()]){
                days[indexes.top()]=i-indexes.top();
                indexes.pop();
            }
            indexes.push(i);
        }
        return days;
    }
};
// @lc code=end
