#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set <int> se;
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        count = 0;
        for(int j = 0; j < s.size(); j++)
            count += s[j] - '0';
        se.insert(count);
    }
    printf("%d\n",se.size() );
    for(auto it = se.begin(); it != se.end(); it++){
        if(it!=se.begin())
            printf(" ");
        printf("%d",*it );
    }


    return 0;
}