/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point &another)
    {
        return (this->x == another.x && this->y == another.y);
    }
};

class Solution
{
private:
    vector<int> parents;

    vector<int> getLands(vector<vector<char>> &grid, int ln, int col)
    {
        vector<int> lands;
        // The place at left and up were scanned so we can igore them here.

        // if (ln > 0 && grid[ln - 1][col] == '1')
        //     lands.push_back(getIndex(grid, ln - 1, col));
        if (ln < grid.size() - 1 && grid[ln + 1][col] == '1')
            lands.push_back(getIndex(grid, ln + 1, col));
        // if (col > 0 && grid[ln][col - 1] == '1')
        //     lands.push_back(getIndex(grid, ln, col - 1));
        if (col < grid[0].size() - 1 && grid[ln][col + 1] == '1')
            lands.push_back(getIndex(grid, ln, col + 1));
        return lands;
    }

    int find(int index)
    {
        if (parents[index] == index)
            return index;

        return parents[index] = find(parents[index]);
    }

    int getIndex(vector<vector<char>> &grid, int ln, int col)
    {
        return ln * grid[0].size() + col;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int lineCount = grid.size(), columnCount = grid[0].size();
        for (int i = 0; i < lineCount * columnCount; i++)
            parents.push_back(i);
        for (int ln = 0; ln < grid.size(); ln++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[ln][col] == '0')
                    continue;
                auto lands = getLands(grid, ln, col);
                for (auto land : lands)
                {
                    int root1 = find(land),
                        root2 = find(getIndex(grid, ln, col));
                    if (root1 != root2)
                        parents[root1] = root2;
                }
            }
        }
        unordered_set<int> roots;
        for (int ln = 0; ln < grid.size(); ln++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[ln][col] == '1')
                    roots.insert(find(getIndex(grid, ln, col)));
            }
        }
        return roots.size();
    }
};
// @lc code=end
#include <iostream>

int main()
{
    vector<vector<char>> grid =
        {{'1', '1', '1', '1', '0'},
         {'1', '1', '0', '1', '0'},
         {'1', '1', '0', '0', '0'},
         {'0', '0', '0', '0', '0'}};
    auto result = Solution().numIslands(grid);
    cout << result;
}

class Solution
{
private:
    vector<Point> path;

    vector<Point> getLands(vector<vector<char>> &grid, Point p)
    {
        // X is for line, y is for column.
        vector<Point> lands;
        if (p.x > 0 && grid[p.x - 1][p.y] == '1')
            lands.push_back(Point(p.x - 1, p.y));
        if (p.x < grid.size() - 1 && grid[p.x + 1][p.y] == '1')
            lands.push_back(Point(p.x + 1, p.y));
        if (p.y > 0 && grid[p.x][p.y - 1] == '1')
            lands.push_back(Point(p.x, p.y - 1));
        if (p.y < grid[0].size() - 1 && grid[p.x][p.y + 1] == '1')
            lands.push_back(Point(p.x, p.y + 1));
        return lands;
    }

    void backtracking(vector<vector<char>> &grid, Point p)
    {
        grid[p.x][p.y] = '0';
        auto lands = getLands(grid, p);

        for (auto land : lands)
        {
            backtracking(grid, land);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int ln = 0; ln < grid.size(); ln++)
        {
            for (int col = 0; col < grid[0].size(); col++)
                if (grid[ln][col] == '1')
                {
                    backtracking(grid, Point(ln, col));
                    count++;
                }
        }
        return count;
    }
};