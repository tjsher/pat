#include <iostream>
#include <algorithm>
using namespace std;


int e[101][101];
bool visit[101];
int n,m;
void dfs(int v)
{
    if(visit[v] == true)
        return;
    visit[v] = true;
    for(int i = 0; i < n; i++)
    {
        if(visit[i] == false && e[v][i] != -1)
            dfs(i);
    }
}

int prim()
{
    //printf("init prim\n");
    int res, u, min = 9999999, lowcost[n];
    fill(visit, visit + 101, false);
    fill(lowcost, lowcost + n, 9999999);
    for(int i = 0; i < m; i++){
        lowcost[i] = e[0][i];
        //printf("lowcost[%d] is %d\n",i+1,lowcost[i] );
    }
    
    visit[0] = true;
    for(int i = 0; i < m -1; i++)
    {
        min = 9999999;
        u = -1;
        for(int j = 0; j < m; j++)
        {
            if(min > lowcost[j] && visit[j] == false)
            {
                min = lowcost[j];
                u = j;
            }
        }
        //printf("u is %d\n", u+1);
        if(u == -1)
            return -1;
        visit[u] = true;
        res += min ;
        //printf("res is %d\n", res );
        for(int j = 0; j < n; j++)
            if(visit[j] == false && lowcost[j] > e[u][j])
                lowcost[j] = e[u][j];
    }
    for(int i = 0;i<n;i++)
        //printf("visit[%d] is %d\n",i+1,visit[i] );
    return res;
}
int main()
{
    int  a, b, c, k = 0;
    
    
    while(scanf("%d%d", &m, &n) != EOF)
    {
        fill(visit, visit + 101, false);
        fill(e[0], e[0] + 101 * 101, 99999999);
        for(int i = 0; i < n; i++) //构造图
        {
            scanf("%d%d%d", &a, &b, &c);
            e[a - 1][b - 1] = c;
            //printf("e[%d][%d] is %d\n",a,b,c );
        }

        int res;
        res = prim();
        if(res == -1)
            printf("?\n");
        else
            printf("%d\n", res );
        //printf("-------------------\n");



    }
    return 0;
}