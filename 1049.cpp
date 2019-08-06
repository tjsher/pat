#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n, res = 0, start = 1;
    scanf("%d", &n);
    int m = start;
    while(start <= n)
    {
        m = start;

        while( m > 0)
        {
            if(m % 10 == 1)
            {
                res++;
            }
            m = m / 10;
        }
        start ++;
    }
    printf("%d", res);
    return 0;
}