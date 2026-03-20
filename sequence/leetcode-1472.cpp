/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
#include <string>
#include <stack>

class BrowserHistory
{
private:
    std::stack<std::string> history, backed;

public:
    BrowserHistory(std::string homepage)
    {
        history.push(homepage);
    }

    void visit(std::string url)
    {
        backed = std::stack<std::string>();
        history.push(url);
    }

    std::string back(int steps)
    {
        while (history.size() > 1 && steps > 0)
        {
            steps--;
            backed.push(history.top());
            history.pop();
        }
        return history.top();
    }

    std::string forward(int steps)
    {
        while (!backed.empty() && steps > 0)
        {
            steps--;
            history.push(backed.top());
            backed.pop();
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
