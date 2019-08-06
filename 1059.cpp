#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> prime (50000, 1);

int main()
{
    int i;
    for(i = 2; i * i < 50000; i++)
        for(int j = 2; j * i < 50000 ; j++)
            prime[i * j] = 0;

    long int n,b;
    int f = 0;
    scanf("%ld", &n);
    b = n;
    i = 2;
    if(n == 1){
        printf("%ld=1",n);
        return 0;
    }
    while(i < 50000)
    {
        if(prime[i] == 0)
        {
            i++;
            continue;
        }
        while(n % i == 0)
        {
            n = n / i;
            prime[i] += 1;
        }
        i++;
    }
    printf("%ld=", b );
    for(i = 0; i < 50000; i++)
    {
        if(prime[i] >= 2)
        {
            printf("%d", i);
            if(prime[i] - 2 >= 1)
                printf("^%d", prime[i] - 1);
            break;
        }
    }
    for(i++; i < 50000; i++)
    {
        if(prime[i] >= 2)
        {
            printf("*%d", i);
            if(prime[i] - 2 >= 1)
                printf("^%d", prime[i] - 1);
        }
    }


    return 0;
}