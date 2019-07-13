/*
统计树的每一层中叶子节点个数
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[100];//二维数组

int c[100], maxLevel = -1;


void dfs(int index, int level)
{
    if(v[index].size() == 0)
    {
        c[level] += 1;
        maxLevel = max(level,maxLevel);
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], level + 1);
    }
}

int main()
{
    int n, m, id, k, temp;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &temp);
            v[id].push_back(temp);
        }
    }
    dfs(1, 0);
    cout << c[0]; //空树也能输出
    for(int i = 1; i <= maxLevel; i++)
    {
        cout << ' ' << c[i];
    }


    return 0;
}

