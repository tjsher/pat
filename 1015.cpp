/*
10进制转换为任意进制
n是10进制，转化为d进制后翻转，
再转化为10进制，判断其是否为素数
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, d;
    while(scanf("%d", &n) != EOF)
    {
        if(n < 0)
            break;
        scanf("%d", &d);
        if(isPrime(n) == false)
        {
            printf("No\n");
            continue;
        }
        int arr[100], len = 0;
        do
        {
            arr[len++] = n % d;
            n = n / d;
        }
        while(n != 0);

        for(int i = 0; i < len; i++)
            n = n*d +arr[i];
        if(isPrime(n))
            printf("Yes\n");
        else
            printf("No\n");
        }


    return 0;
}