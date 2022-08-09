#include <bits/stdc++.h>
using namespace std;
#define segtree int lft = node << 1, rgt = lft | 1, mid = (b + e) >> 1
const int N = 100010;

int arr[N];
vector < int > tree[N << 2];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].push_back(arr[b]);
        return;
    }
    segtree;
    build(lft, b, mid);
    build(rgt, mid + 1, e);
    merge(tree[lft].begin(), tree[lft].end(), tree[rgt].begin(), tree[rgt].end(), back_inserter(tree[node]));
}

int Q(int node, int b, int e, int i, int j, int k)
{
    if(b > j || e < i)
        return 0;
    if(b >= i && e <= j)
    {
        return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }
    segtree;
    int p1 = Q(lft, b, mid, i, j, k);
    int p2 = Q(rgt, mid + 1, e, i, j, k);
    return p1 + p2;
}

int main()
{
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
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        int ans = Q(1, 1, n, i, j, k);
        printf("%d\n", ans);
    }
}
