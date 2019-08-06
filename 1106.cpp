#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
double p, r;
map <int, vector<int>> e;
double res[100000];
int isleaf[100000];

void dfs(int v)
{
    if(e[v].size() == 0)
        isleaf[v] = 1;
    for(int i = 0; i < e[v].size(); i++)
    {
        res[e[v][i]] = res[v] * (1 + r);
        dfs(e[v][i]);
    }
}

int main()
{
    int n;
    scanf("%d%lf%lf", &n, &p, &r);
    res[0] = p;
    r = r / 100;
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            int a;
            scanf("%d", &a);
            if(a != 0)
                e[i].push_back(a);
        }

    }
    dfs(0);
    double minn = 9999999;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(minn > res[i] && isleaf[i] == 1)
        {
            minn = res[i];
            count = 0;
        }
        if(minn == res[i] && isleaf[i] == 1)
        {
            minn = res[i];
            count++;
        }
    }
    printf("%.4lf %d", minn, count );

    return 0;
}