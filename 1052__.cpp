#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int add, key, next;
} l[100000];

bool cmp(node a, node b)
{
    return a.key < b.key;
}
int main()
{
    int n, add, first, k, nt;
    scanf("%d%d", &n, &first);
    for(int i = 0; i < n; i++)
    {

        scanf("%d%d%d", &add, &k, &nt);
        l[i].add = add;
        l[i].key = k;
        l[i].next = nt;
    }

    if(n == 0)
        printf("0 -1\n");
    else
    {
        sort(l, l + n, cmp);
        printf("%d %d\n", n, l[0].add );
        for(int i = 0; i < n; i++)
        {

            if(i == n - 1)
            {
                printf("%05d %d -1\n", l[i].add, l[i].key );
                break;
            }

            printf("%05d %d %05d\n", l[i].add, l[i].key, l[i + 1].add );

        }
    }
    return 0;

}