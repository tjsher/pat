#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int id, grade;
    string name;
};
bool cmp1(node a, node b)
{
    return a.id < b.id;
}
bool cmp2(node a, node b)
{
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}
bool cmp3(node a, node b)
{
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}
int n, c;
vector<node> stu;
int main()
{
    scanf("%d%d", &n, &c);
    node t;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &t.id);
        cin >> t.name;
        scanf("%d", &t.grade);
        stu.push_back(t);
    }
    switch(c)
    {
    case 1:
        sort(stu.begin(), stu.end(), cmp1);
        break;
    case 2:
        sort(stu.begin(), stu.end(), cmp2);
        break;
    case 3:
        sort(stu.begin(), stu.end(), cmp3);
        break;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%06d ", stu[i].id);
        cout << stu[i].name;
        printf(" %d\n", stu[i].grade );
    }

    return 0;
}