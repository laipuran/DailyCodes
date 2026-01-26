/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
#include <string>
#include <list>
#include <sstream>
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";

        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> strs;
        stringstream ss(data);
        string str;
        while (getline(ss, str, ','))
            strs.push_back(str);
        return deserialize(strs);
    }

    TreeNode *deserialize(list<string> &data)
    {
        string str = data.front();
        data.pop_front();
        if (str == "#")
            return nullptr;

        TreeNode *node = new TreeNode(stoi(str));
        node->left = deserialize(data);
        node->right = deserialize(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
#include <string>
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "null";
        if (root->left == nullptr && root->right == nullptr)
            return to_string(root->val);
        else
            return to_string(root->val) + "[" + serialize(root->left) + "," + serialize(root->right) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        return deserialize(data, 0, data.length());
    }

private:
    // Be aware of the negative.
    bool isNumber(string str)
    {
        for (char ch : str)
            if (!isdigit(ch) && ch != '-')
                return false;
        return true;
    }

    TreeNode *deserialize(const string &data, int begin, int end)
    {
        if (begin == end || data.substr(begin, end - begin) == "null")
            return nullptr;
        if (isNumber(data.substr(begin, end - begin)))
            return new TreeNode(stoi(data.substr(begin, end - begin)));

        int bracket = begin;
        while (data[bracket] != '[')
            bracket++;
        int number = stoi(data.substr(begin, bracket - begin));
        begin = bracket;

        int index = begin + 1;
        int count = 0;
        // Wrong for not checking which comma it is.
        // while (data[index] != ',')
        //     index++;

        for (; index < end; index++)
        {
            if (data[index] == '[')
            {
                count++;
                continue;
            }
            if (data[index] == ']')
            {
                count--;
                continue;
            }
            if (data[index] == ',' && count == 0)
                break;
        }

        TreeNode *node = new TreeNode(number);
        node->left = deserialize(data, begin + 1, index);
        node->right = deserialize(data, index + 1, end - 1);
        return node;
    }
};

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);

    Codec cdc;
    cdc.deserialize(cdc.serialize(node));
}