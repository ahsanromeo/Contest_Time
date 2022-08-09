#include <bits/stdc++.h>
using namespace std;

const int N = 501;
const int inf = 1000 * 1000 * 1000;

int mat[N][N], nxt[N][N];
vector < int > path;
int n, m;

void find_path(int i, int j)
{
    path.clear();
    path.push_back(i);
    while(i != j)
    {
        i = nxt[i][j];
        path.push_back(i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            mat[i][j] = i == j ? 0 : inf;
            nxt[i][j] = j;
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        mat[u][v] = min(mat[u][v], c);
        //mat[v][u] = min(mat[v][u], c);
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                int curr = mat[i][k] + mat[k][j];
                if(mat[i][j] > curr)
                {
                    mat[i][j] = curr;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    int x, y;
    while(scanf("%d %d", &x, &y) == 2)
    {
        if(mat[x][y] == inf)
        {
            cout << "No Path" << endl;
            continue;
        }
        cout << "Cost: " << mat[x][y] << endl;
        find_path(x, y);
        for(int i = 0; i < path.size(); ++i)
        {
            if(i > 0)
                putchar(' ');
            cout << path[i];
        }
        cout << endl;
    }
    return 0;
}
