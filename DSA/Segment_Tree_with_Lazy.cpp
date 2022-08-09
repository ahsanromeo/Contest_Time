#include <bits/stdc++.h>
using namespace std;
#define segtree int lft = node << 1, rgt = lft | 1, mid = (b + e) >> 1
const int N = 100010;
int arr[N], tree[N << 2], lazy[N << 2];


void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    segtree;
    build(lft, b, mid);
    build(rgt, mid + 1, e);
    tree[node] = tree[lft] + tree[rgt];
}

void down(int node, int b, int e)
{
    if(lazy[node] == 0)
        return;
    tree[node] += lazy[node];
    if(b != e)
    {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}

void U(int node, int b, int e, int i, int j, int k)
{
    down(node, b, e);
    if(b > j || e < i)
        return;
    if(b >= i && e <= j)
    {
        tree[node] += k;
        down(node, b, e);
        return;
    }
    segtree;
    U(lft, b, mid, i, j, k);
    U(rgt, mid + 1, e, i, j, k);
    tree[node] = tree[lft] + tree[rgt];
}

int Q(int node, int b, int e, int i, int j)
{
    down(node, b, e);
    if(b > i || e < i)
        return 0;
    if(b >= i && e <= i)
    {
        return tree[node];
    }
    segtree;
    int p1 = Q(lft, b, mid, i, j);
    int p2 = Q(rgt, mid + 1, e, i, j);
    return p1 + p2;
}

int main()
{
    memset(lazy, 0, sizeof lazy);
    memset(tree, 0, sizeof tree);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", arr + i);
    }
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int t, i, j;
        scanf("%d %d %d", &t, &i, &j);
        if(t == 1)
        {
            int k;
            scanf("%d", &k);
            U(1, 1, n, i, j, k);
        }
        else
        {
            int ans = Q(1, 1, n, i, j);
            printf("%d\n", ans);
        }
    }
    return 0;
}
