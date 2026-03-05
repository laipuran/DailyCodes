#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
// Allocate 4n space to ensure indices stay within bounds
int tree[MAXN * 4];

// Pull up information from children to update current node
void pushUp(int node)
{
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

// Recursively build the segment tree from the input array
void build(const vector<int> &a, int node, int start, int end)
{
    if (start == end)
    {
        // Leaf node: store original array value
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(a, node << 1, start, mid);       // Build left child
    build(a, node << 1 | 1, mid + 1, end); // Build right child
    pushUp(node);                          // Merge results back up
}

// Update value at a specific index: a[idx] = val
void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        // Target leaf found
        tree[node] = val;
        return;
    }
    int mid = (start + end) >> 1;
    if (idx <= mid)
        update(node << 1, start, mid, idx, val); // Search in left subtree
    else
        update(node << 1 | 1, mid + 1, end, idx, val); // Search in right subtree
    pushUp(node);                                      // Backtrack and update all affected parent nodes
}

// Query the sum within the range [L, R]
int query(int node, int start, int end, int L, int R)
{
    // Current node range is completely within the target range
    if (L <= start && end <= R)
    {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    int sum = 0;

    // Check if left child overlaps with query range
    if (L <= mid)
        sum += query(node << 1, start, mid, L, R);
    // Check if right child overlaps with query range
    if (R > mid)
        sum += query(node << 1 | 1, mid + 1, end, L, R);
    return sum;
}