#include <iostream>
#include <algorithm>
using namespace std;

int v[1001][1001];
int visit[1001];
int n;
void dfs(int from)
{   printf("%d ",from);
    visit[from] = 1;
    for(int i = 0; i < n; i++)
    {
        if(v[from][i] && !visit[i])
            dfs(i);
    }

}
int main()
{
    int  m, k, from, to;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        v[from][to] =v[to][from] =  1;
    }

    int city, res = 0;
    for(int i = 0; i < k; i++)
    {
        res = 0;
        fill(visit, visit + n, 0);
        scanf("%d", &city);
        visit[city] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(!visit[j])
            {
                dfs(j);
                res++;
            }
            printf("\n");
        }
        //printf("%d\n", res - 1);
    }
    return 0;
}