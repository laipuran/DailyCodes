/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
    private:
    vector<int> numbers;
    vector<vector<int>> result;
    vector<int> path;

    bool has(int num){
        for(int item:path)if(item==num)return true;
        return false;
    }

    void backtracking(){
        if(path.size()==numbers.size()){
            result.push_back(path);
            return;
        }

        for(int i=0;i<numbers.size();i++){
            if(has(numbers[i]))continue;
            path.push_back(numbers[i]);
            backtracking();
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        numbers=nums;
        backtracking();
        return result;
    }
};
// @lc code=end
