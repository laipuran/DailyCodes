/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

struct AVLNode
{
    int val;
    int height;
    int size;
    AVLNode *left, *right;
    AVLNode(int val) : val(val), height(1), size(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    int getHeight(AVLNode *node)
    {
        return node == nullptr ? 0 : node->height;
    }

    int getSize(AVLNode *node)
    {
        return node == nullptr ? 0 : node->size;
    }

    void updateHeight(AVLNode *node)
    {
        if (node == nullptr)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void updateSize(AVLNode *node)
    {
        if (node == nullptr)
            return;
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }

    int getBalanceFactor(AVLNode *node)
    {
        return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *rightRotate(AVLNode *node)
    {
        auto l = node->left;
        auto lr = l->right;

        l->right = node;
        node->left = lr;

        updateHeight(node);
        updateHeight(l);
        updateSize(node);
        updateSize(l);

        return l;
    }

    AVLNode *leftRotate(AVLNode *node)
    {
        auto r = node->right;
        auto rl = r->left;

        r->left = node;
        node->right = rl;

        updateHeight(node);
        updateHeight(r);
        updateSize(node);
        updateSize(r);

        return r;
    }

    AVLNode *rebalance(AVLNode *node)
    {
        if (node == nullptr)
            return nullptr;

        updateHeight(node);

        int factor1 = getBalanceFactor(node);
        if (factor1 > 1)
        {
            int factor2 = getBalanceFactor(node->left);
            if (factor2 >= 0)
                return rightRotate(node);
            else
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if (factor1 < -1)
        {
            int factor2 = getBalanceFactor(node->right);
            if (factor2 <= 0)
                return leftRotate(node);
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

public:
    AVLNode *insert(AVLNode *node, int val, int &count)
    {
        if (node == nullptr)
            return new AVLNode(val);

        // Allow duplicate items
        if (val <= node->val)
            node->left = insert(node->left, val, count);
        else if (val > node->val)
        {
            count += getSize(node->left) + 1;
            node->right = insert(node->right, val, count);
        }
        
        /**
         * WHY UPDATE SIZE DURING BACKTRACKING:
         * 1. Recursive Descent: We travel down to find the insertion spot. 
         * The parent nodes' size values remain "stale" during this phase.
         * 2. Recursive Backtracking: After the new leaf is added, we return 
         * to the parent. Only now do we know that a child subtree has 
         * grown. We must recalculate node->size immediately so that 
         * the NEXT parent in the call stack can use the updated value 
         * via getSize(node->left/right).
         */
        updateSize(node);

        return rebalance(node);
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size());

        AVLTree tree;
        AVLNode *root = nullptr;

        // Remember to reverse
        for (int i=nums.size()-1;i>=0;i--)
        {
            int count = 0;
            root = tree.insert(root, nums[i], count);
            result[i]=count;
        }
        return result;
    }
};
// @lc code=end
