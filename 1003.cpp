/*
dijkstra找到最短路径的同时，
在每次分支点都要找最大点权。
不需要最短路径。
*/

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
//边权，点权，距离，分支个数，答案所需点权
bool visit[510];
const int inf = 99999999;

int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    for(int k = 0; k < m; k++)
    {
        int i, j, l;
        scanf("%d%d%d", &i, &j, &l);
        e[i][j] = e[j][i] = l;

    }

    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(!visit[v] && e[u][v] != inf)
            {
                if(dis[u] + e[u][v] < dis[v])
                {
                    num[v] = num[u];
                    dis[v] = dis[u] + e[u][v];
                    w[v] = w[u] + weight[v];
                }
                else if(dis[u] + e[u][v] == dis[v])
                {
                    num[v] = num[u] + num[v];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d",num[c2],w[c2]);

    return 0;

}