#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
vector < int > tree[N];
int n, level[N], par[N], table[N][11];
void clear()
{
    for(int i = 0; i < N; ++i)
    {
        level[i] = par[i] = -1;
        for(int j = 0; j < 11; ++j)
            table[i][j] = -1;
        tree[i].clear();
    }
}
void input()
{
    scanf("%d", &n);
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void dfs(int u, int d)
{
    level[u] = d;
    for(const auto& v : tree[u])
    {
        if(level[v] == -1)
        {
            par[v] = u;
            dfs(v, d + 1);
        }
    }
}

void create_spare_table()
{
    dfs(0, 0); /// generating all nodes level and 1st parent
    for(int i = 0; i < n; ++i)
        table[i][0] = par[i];  /// every i'th node 1st parent is par[i]
    for(int j = 1; (1 << j) < n; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            int p = table[i][j - 1];
            if(p != -1) /// if the parent's j - 1'th parent exists
                table[i][j] = table[p][j - 1];
        }
    }
}

int LCA(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);  /// let u be deeper than v always
    int log = log2(level[u]) + 1;
    for(int i = log; i >= 0; --i)  /// take u to the same level with v
    {
        if(level[u] - (1 << i) >= level[v])
        {
            u = table[u][i];
        }
    }
    if(u == v) /// if u and v are same now then return anyone
        return u;
    for(int i = log; i >= 0; --i) /// take them up until their parent is same
    {
        if(table[u][i] != -1 && table[u][i] != table[v][i])
        {
            u = table[u][i];
            v = table[v][i];
        }
    }
    return par[u]; /// return the common parent
}

void query()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int u, v;
        scanf("%d %d", &u, &v); /// 0 based index
        printf("%d\n", LCA(u, v));
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    clear();
    input();
    create_spare_table();
    query();
    return 0;
}
