#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{

    int n, m, k, q, t;
    int wait[1001], ask[1001];
    scanf("%d %d %d %d", &n, &m, &k, &q);
    queue<int> line[n], time[k + 1] = {0};
    for(int i = 0; i < k; i++)
    {
        scanf("%d", t);
        wait[i] = t;
    }
    int w = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            line[i].push(wait(w));
            w++;
        }
    }
    int vacancy[n], first = 9999;
    while(w < k)
    {
        fill(vacancy, vacancy + n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!line.empty())
            {
                time[i] += line[i].front();
                line[i].pop();
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(wait[i] < first)
            {
                first = wait[i];
                vacancy[i] = 1;
            }

        }

    }


    for (int i = 0; i < q; i++)
    {
        printf("");
    }
    return 0;
}