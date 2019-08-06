#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <int> v, res, temp;
int n, k, p, maxfacsum = -1;

void dfs(int index, int level, int tempsum, int facsum)
{
    if(level == k)
    {
        if(tempsum == n && facsum > maxfacsum )
        {
            res = temp;
            maxfacsum = facsum;
        }
        return;
    }
    while(index >= 1)
    {
        if(tempsum + v[index] <= n)
        {
            temp[level] = index;
            dfs(index, level + 1, tempsum + v[index], facsum + index);
        }
        if(index == 1)
            return;
        index--;
    }

}

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    int tep = 0, index = 1;
    while (tep <= n)
    {
        v.push_back(tep);
        tep = pow(index, p);
        index++;
    }
    temp.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if(maxfacsum == -1)
    {
        printf("Impossible\n");
        return 0;
    }
    printf("%d = %d^%d", n, res[0], p);
    for(int i = 1; i < k; i++)
        printf(" + %d^%d", res[i], p );


    return 0;
}