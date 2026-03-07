/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    typedef unordered_map<char, int> UCI;
    UCI needs;
    int minCount = 0x3f3f3f;
    int count = 0;

    // Solution improved by Gemini
    void backtracking(const vector<UCI> &pieces, string &target)
    {
        char first_needed = '\0';
        for (char ch : target)
        {
            if (needs[ch] > 0)
            {
                first_needed = ch;
                break;
            }
        }

        if (first_needed == '\0')
        {
            minCount = min(minCount, count);
            return;
        }

        if (count + 1 >= minCount)
            return;

        for (int i = 0; i < pieces.size(); i++)
        {
            if (pieces[i].count(first_needed) == 0)
                continue;

            for (auto const &[ch, val] : pieces[i])
                needs[ch] -= val;
            count++;

            backtracking(pieces, target);

            count--;
            for (auto const &[ch, val] : pieces[i])
                needs[ch] += val;
        }
    }

public:
    int minStickers(vector<string> &stickers, string target)
    {
        for (char ch : target)
        {
            needs[ch]++;
        }
        vector<bool> has(26, false);

        vector<UCI> pieces;
        for (string str : stickers)
        {
            UCI u;
            for (char ch : str)
            {
                if (needs.count(ch) == 0)
                    continue;
                u[ch]++;
                has[ch - 'a'] = true;
            }
            if (!u.empty())
                pieces.push_back(u);
        }

        for (int i = 0; i < 26; i++)
        {
            if (needs.count(i + 'a') != 0 && has[i] == false)
                return -1;
        }

        backtracking(pieces, target);
        return minCount;
    }
};
// @lc code=end
