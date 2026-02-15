#include <iostream>
#include <algorithm>

struct AVLNode {
    int val;
    int height;
    AVLNode *left, *right;
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    // Helper function to get height safely (handles null pointers)
    int getHeight(AVLNode* node) { 
        return node ? node->height : 0; 
    }

    // Update node height based on child subtrees
    void updateHeight(AVLNode* node) {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Get Balance Factor (BF = height of left - height of right)
    int getBalanceFactor(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // --- Core Rotation Logic ---

    // Right Rotate (used for LL case)
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights (order matters: bottom node first)
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }

    // Left Rotate (used for RR case)
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        // Return new root
        return y;
    }

    // --- Dynamic Balance Maintenance ---
    AVLNode* rebalance(AVLNode* node) {
        if (!node) return nullptr;

        // Update height of current node after insertion/deletion
        updateHeight(node);
        int bf = getBalanceFactor(node);

        // Case 1: LL (Left-Left) - Heavy on the left of left child
        if (bf > 1 && getBalanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }

        // Case 2: LR (Left-Right) - Heavy on the right of left child
        if (bf > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left); // Convert LR to LL
            return rightRotate(node);
        }

        // Case 3: RR (Right-Right) - Heavy on the right of right child
        if (bf < -1 && getBalanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }

        // Case 4: RL (Right-Left) - Heavy on the left of right child
        if (bf < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right); // Convert RL to RR
            return leftRotate(node);
        }

        return node; // Return node if it is already balanced
    }

public:
    // Insert a value and maintain balance via recursion/backtracking
    AVLNode* insert(AVLNode* node, int val) {
        if (!node) return new AVLNode(val);

        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        } else {
            return node; // Duplicate values not allowed in this implementation
        }

        // Rebalance the node during backtracking
        return rebalance(node);
    }
};