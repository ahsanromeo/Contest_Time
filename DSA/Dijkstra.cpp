/// Single Source, Shortest Path, Dijkstra

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 2e9;
vector < pair < int , int > > G[N]; /// node cost, node number
int dis[N], par[N];
bool used[N];

void Dijkstra(int s)
{
    priority_queue < pair < int , int >,
    vector < pair < int , int > >,
    greater < pair < int , int > > > pq;

    fill(dis, dis + N, inf);
    fill(par, par + N, -1);
    fill(used, used + N, false);

    pq.push(make_pair(0, s));
    dis[s] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();
        used[u] = true;
        for(int i = 0; i < (int)G[u].size(); ++i)
        {
            int v = G[u][i].first;
            int cost = G[u][i].second;
            if(dis[v] > dis[u] + cost)
            {
                dis[v] = dis[u] + cost;
                par[v] = u;
                if(!used[v])
                    pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y, z; cin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    Dijkstra(1);
    for(int i = 1; i <= n; ++i)
    {
        cout << i << ' ' << dis[i] << endl;
    }
    return 0;
}
