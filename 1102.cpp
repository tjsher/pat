#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int left, right;
};
vector <node> t;
queue <int> q;
vector <int> res;
int n, f[11], vis[11];

int invert(int root)
{
    if(root == -1)
        return -1;
    int temp = t[root].left;
    t[root].left = invert(t[root].right);
    t[root].right = invert(temp);
    return root;


}

void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(t[root].left);
    res.push_back(root);
    inOrder(t[root].right);

}

void levelOrder()
{
    if(q.size() == 0)
        return;
    int temp = q.front();
    q.pop();
    res.push_back(temp);
    if(t[temp].left != -1)
        q.push(t[temp].left);
    if(t[temp].right != -1)
        q.push(t[temp].right);
    levelOrder();
}


int main()
{
    int root;
    scanf("%d", &n);
    char c1, c2;
    for(int i = 0; i < n; i++)
    {
        node a = {-1, -1};
        cin >> c1 >> c2;
        if(c1 != '-')
        {
            a.left = c1 - '0';
            f[c1 - '0'] = 1;
        }

        if(c2 != '-')
        {
            f[c2 - '0'] = 1;
            a.right = c2 - '0';
        }
        t.push_back(a);
    }
    for(int i = 0; i < n; i++)
        if(f[i] == 0)
            root = i;
    invert(root);
    q.push(root);
    levelOrder();
    int i;
    for(i = 0; i < res.size() - 1; i++)
        printf("%d ", res[i] );
    printf("%d\n", res[i] );
    res.clear();
    inOrder(root);
    for(i = 0; i < res.size() - 1; i++)
        printf("%d ", res[i] );
    printf("%d\n", res[i] );



    return 0;
}