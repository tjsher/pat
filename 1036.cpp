#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    string name, id;
    int grade;
};

bool cmp(node a, node b)
{
    return a.grade > b.grade;
}

vector<node> m, f;
int main()
{
    int n;
    scanf("%d", &n);
    string a, b, c;
    int d;
    node s;
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        s.name = a;
        s.id = c;
        s.grade = d;
        if(b == "M")
            m.push_back(s);
        if(b == "F")
            f.push_back(s);
    }
    sort(m.begin(), m.end(), cmp);
    sort(f.begin(), f.end(), cmp);
    if(f.size() == 0)
    {
        printf("Absent\n" );
        flag = true;
    }
    else
        cout << f[0].name << " " << f[0].id << endl;
    if(m.size() == 0)
    {
        printf("Absent\n" );
        flag = true;
    }
    else
        cout << m[m.size() - 1].name << " " << m[m.size() - 1].id << endl;
    if(flag == true)
        printf("NA\n");
    else
        printf("%d\n", f[0].grade - m[m.size() - 1].grade);
    return 0;
}