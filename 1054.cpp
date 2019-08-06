#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <int, int> ans;
int main()
{
    int m, n, c, _max = 0;
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &c);
            ans[c] += 1;
        }
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        if(it->second >= m * n  / 2)
            if(_max < it->second )
                _max = it->first;
    }
    printf("%d",_max );
    return 0;
}