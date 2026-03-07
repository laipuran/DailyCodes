#include <iostream>
#include <vector>

using namespace std;

// Using long long to avoid overflow
typedef long long ll;

const int MAXN = 100005;

struct Node
{
    ll sum;
    ll lazy;
} tree[MAXN * 4];

void pushUp(int node)
{
    tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
}

void pushDown(int node, int start, int end)
{
    if (tree[node].lazy)
    {
        int mid = start + ((end - start) >> 1);
        int leftNode = node << 1;
        int rightNode = node << 1 | 1;

        tree[leftNode].lazy += tree[node].lazy;
        tree[rightNode].lazy += tree[node].lazy;

        tree[leftNode].sum += tree[node].lazy * (mid - start + 1);
        tree[rightNode].sum += tree[node].lazy * (end - mid);

        tree[node].lazy = 0;
    }
}

void build(int node, int start, int end, const vector<ll> &nums)
{
    tree[node].lazy = 0;
    if (start == end)
    {
        tree[node].sum = nums[start - 1];
        return;
    }
    int mid = start + ((end - start) >> 1);
    build(node << 1, start, mid, nums);
    build(node << 1 | 1, mid + 1, end, nums);
    pushUp(node);
}

void update(int node, int start, int end, int l, int r, ll val)
{
    if (l <= start && end <= r)
    {
        tree[node].sum += val * (end - start + 1);
        tree[node].lazy += val;
        return;
    }
    pushDown(node, start, end);
    int mid = start + ((end - start) >> 1);
    if (l <= mid)
        update(node << 1, start, mid, l, r, val);
    if (r > mid)
        update(node << 1 | 1, mid + 1, end, l, r, val);
    pushUp(node);
}

ll query(int node, int start, int end, int l, int r)
{
    if (l <= start && end <= r)
        return tree[node].sum;
    pushDown(node, start, end);
    int mid = start + ((end - start) >> 1);
    ll res = 0;
    if (l <= mid)
        res += query(node << 1, start, mid, l, r);
    if (r > mid)
        res += query(node << 1 | 1, mid + 1, end, l, r);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (cin >> n >> m)
    {
        vector<ll> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        build(1, 1, n, nums);
        while (m--)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int x, y;
                ll k;
                cin >> x >> y >> k;
                update(1, 1, n, x, y, k);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                cout << query(1, 1, n, x, y) << '\n';
            }
        }
    }
    return 0;
}
