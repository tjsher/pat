#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct TreeNode *Node;
struct TreeNode
{
    Node left;
    Node right;
    int data;

    TreeNode()
    {
        left = right = NULL;
    }
};

int *pre;
int N;
vector<int> preOrderV;
vector<int> mpreOrderV;
vector<int> result;

void insert(Node &T, int num)
{
    if(!T)
    {
        T = new TreeNode();
        T->data = num;
        return;
    }

    if(num < T->data)
    {
        insert(T->left, num);
    }
    else
    {
        insert(T->right, num);
    }
}

void preOrder(Node T)
{
    if(!T) return;
    preOrderV.push_back(T->data);
    preOrder(T->left);
    preOrder(T->right);

}

void postOrder(Node T)
{
    if(!T) return;
    postOrder(T->left);
    postOrder(T->right);
    result.push_back(T->data);
}

void MBSTpreOrder(Node T)
{
    if(!T) return;
    mpreOrderV.push_back(T->data);
    MBSTpreOrder(T->right);
    MBSTpreOrder(T->left);
}

bool arrayEqual2Vector(int *arr, vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(arr[i] != vec[i]) return false;
    }
    return true;
}

void mirror(Node T)
{
    if(!T)return;
    Node temp = T->left;
    T->left = T->right;
    T->right = temp;
    mirror(T->left);
    mirror(T->right);
}

int main()
{
    cin >> N;
    pre = (int *)malloc(sizeof(int) * N);
    int num;
    Node T = NULL;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        pre[i] = num;
        insert(T, num);
    }
    preOrderV.clear();
    mpreOrderV.clear();
    result.clear();

    preOrder(T);
    MBSTpreOrder(T);

    if(arrayEqual2Vector(pre, preOrderV))
    {
        cout << "YES" << endl;
        postOrder(T);
    }
    else if(arrayEqual2Vector(pre, mpreOrderV))
    {
        cout << "YES" << endl;
        mirror(T);
        postOrder(T);
    }
    else
    {
        cout << "NO" << endl;
    }

    if(result.size() != 0)
    {
        cout << result[0];
        for(int i = 1; i < result.size(); i++)
            printf(" %d", result[i]);
        cout << endl;
    }

    return 0;
}
