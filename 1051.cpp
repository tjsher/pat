#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
    int m, n, k;

    scanf("%d%d%d", &m, &n, &k);

    for(int q = 0; q < k; q++)
    {
        int cur = 1;
        vector <int> v;
        stack <int> s;
        v.resize(n + 1);
        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);

        for (int i = 1; i <= n; i++)
        {
            s.push(i);
            if(s.size() > m)
                break;
            while(s.empty() == false && s.top() == v[cur])
            {
                cur++;
                s.pop();
            }
        }
        if(cur == n + 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}