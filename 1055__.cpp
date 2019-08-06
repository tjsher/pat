#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    string name;
    int a, w; //age,wealth
};

bool cmp(node a, node b)
{
    return a.w == b.w ? (a.a == b.a ?   a.name < b.name: a.a < b.a ) : a.w > b.w;
}

vector <node> ans;
int main()
{
    int n, k;
    node t;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        cin >> t.name;
        scanf("%d%d", &t.a, &t.w);
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end(), cmp);

    for(int q = 1; q <= k; q++)
    {
        int maxx, la, ra, i = 0,f=0;
        scanf("%d%d%d", &maxx, &la, &ra);
        printf("Case #%d:\n", q );
        vector <node> res;
        for(int j = 0; j < ans.size(); j++)
        {
            if(ans[j].a <= ra && i < maxx && ans[j].a >= la)
            {
                res.push_back(ans[j]);
                i++;
                f = 1;
            }
        }

        if(f == 0)
            printf("None\n");
        else
        {
            sort(res.begin(), res.end(),cmp);
            for(int i = 0;i<res.size();i++)
                cout <<res[i].name<< " "<<res[i].a<< " "<<res[i].w<<endl;
        }

    }
    return 0;
}