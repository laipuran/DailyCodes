/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

// Backtracking provided by Gemini:
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);     
            backtracking(n, k, i + 1);  
            path.pop_back();           
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

// @lc code=end

// My solution:
class Solution
{
    vector<vector<int>> combine(int n, int k, int index)
    {
        vector<vector<int>> combinations;
        if (index + k - 1 > n || k == 0)
            return combinations;
        if (index <= n && k == 1)
        {
            for (int i = index; i <= n; i++)
                combinations.push_back(vector<int>(1, i));
            return combinations;
        }
        for (int i = index; i <= n; i++)
        {
            vector<vector<int>> temp = combine(n, k - 1, i + 1);
            for (int j = 0; j < temp.size(); j++)
                temp[j].push_back(i);
            combinations.insert(combinations.end(), make_move_iterator(temp.begin()), make_move_iterator(temp.end()));
        }
        return combinations;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        return combine(n, k, 1);
    }
};

int main()
{
    int n = 4, i = 2;
    Solution sln;
    auto result = sln.combine(4, 2);
}