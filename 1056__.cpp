#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int arr[100001];
stack <int> s;
int main()
{
    int n, t, c = 0;
    char opr[15];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &opr);
        if(opr[1] == 'u')
        {
            scanf("%d", &t);
            s.push(t);
            arr[c++] = t;
        }
        else if(opr[1] == 'o')
        {
            if(s.size() == 0)
                printf("Invalid\n");
            else
            {
                printf("%d\n", s.top());
                s.pop();
                c--;
            }
        }
        else
        {
            if(s.size() == 0)
                printf("Invalid\n");
            else
            {
                sort(arr, arr + c);
                printf("%d\n", arr[(s.size() + 1) / 2 - 1] );
            }
        }
    }
    return 0;
}