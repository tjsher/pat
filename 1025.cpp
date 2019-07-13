#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    long long id;
    int finalRank, local, localRank, score;
};

bool cmp(node a, node b)
{
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

vector<node> t;
int n, k;
int main()
{
    int count = 0, b;
    long long a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        count += k;
        vector<node> d;
        for(int j = 0; j < k; j++ )
        {
            node c;
            scanf("%lld%d", &a, &b);
            c.id = a;
            c.score = b;
            c.local = i+1;
            d.push_back(c);
        }
        sort(d.begin(), d.end(), cmp);
        d[0].localRank = 1;
        int rank = 2;
        t.push_back(d[0]);
        for(int j = 1; j < k; j++)
        {

            if(d[j].score == d[j - 1].score)
                d[j].localRank = d[j - 1].localRank;
            else
                d[j].localRank = rank;
            rank++;
            t.push_back(d[j]);
        }
        /*
        for(int j = 0; j < k; j++)
            printf("%d,id is %lld,localRank is %d\n",
                d[j].local,d[j].id,d[j].localRank );
                */
    }
    sort(t.begin(), t.end(), cmp);
    t[0].finalRank = 1;
    int rank = 2;
    for(int i = 1; i < t.size(); i++)
    {
        if(t[i].score != t[i - 1].score)
            t[i].finalRank = rank;
        else
            t[i].finalRank = t[i - 1].finalRank;
        rank ++;

    }
    printf("%d\n", count);
    for(int i = 0; i < t.size(); i++)
        printf("%013lld %d %d %d\n", t[i].id, t[i].finalRank,
               t[i].local, t[i].localRank );
    return 0;
}