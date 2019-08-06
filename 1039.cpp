/*
将学生姓名转换为数组下标，减少空间（未完成）
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<int>> name;
vector <string> u;
int main()
{

    int n, k;
    string s;

    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int index, num;
        scanf("%d%d", &index, &num);
        for(int j = 0; j < num; j++)
        {
            cin >> s;
            u.push_back(s);
            name[s].push_back(index);
        }
    }
    for(int i = 0; i < u.size(); i++)
        sort(name[u[i]].begin(), name[u[i]].end());

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cout << s << " " << name[s].size() << " ";
        for(int j = 0; j < name[s].size() - 1; j++)
            printf("%d ", name[s][j] );
        printf("%d\n", name[s][name[s].size() - 1] );
    }

    return 0;
}