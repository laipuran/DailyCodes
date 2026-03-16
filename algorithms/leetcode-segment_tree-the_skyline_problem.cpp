/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    int max;
    Node *left, *right;
    Node(int max) : max(max), left(nullptr), right(nullptr) {}
    Node() : max(0), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    Node *root;

    void put(Node *&node, uint begin, uint end, int l, int r, int val)
    {
        if (node == nullptr)
        {
            node = new Node();
        }

        if (val <= node->max)
            return;

        if (begin >= l && end <= r)
        {
            node->max = max(node->max, val);
            return;
        }

        int mid = begin + (end - begin) / 2;
        if (mid >= l)
            put(node->left, begin, mid, l, r, val);
        if (mid < r)
            put(node->right, mid + 1, end, l, r, val);
    }

    int query(Node *&node, uint begin, uint end, int index)
    {
        if (begin == end)
            return node->max;

        pushDown(node);

        int mid = begin + (end - begin) / 2;
        if (index <= mid)
        {
            return query(node->left, begin, mid, index);
        }
        else
            return query(node->right, mid + 1, end, index);
    }

    void pushDown(Node *node)
    {
        if (node->left == nullptr)
            node->left = new Node();
        if (node->right == nullptr)
            node->right = new Node();

        node->left->max = max(node->left->max, node->max);
        node->right->max = max(node->right->max, node->max);
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        root = new Node();

        // Use unsigned int to avoid overflow.
        uint max = 2147483647;
        for (const auto &vec : buildings)
        {
            put(root, 0, max, vec[0], vec[1] - 1, vec[2]);
        }

        vector<int> points(buildings.size() * 2);

        for (int i = 0; i < buildings.size(); i++)
        {
            const auto &vec = buildings[i];
            points[i * 2] = vec[0];
            points[i * 2 + 1] = vec[1];
        }

        sort(points.begin(), points.end());

        vector<vector<int>> result;
        for (int pt : points)
        {
            if (result.size() != 0 && result.back()[0] == pt)
                continue;
            int h = query(root, 0, max, pt);

            // Remember to remove duplicates.
            if (result.size() != 0 && result.back()[1] == h)
                continue;
            result.push_back({pt, h});
        }

        return result;
    }
};
// @lc code=end
