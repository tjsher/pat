#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3;
    int c1, c2, c3, t, f = 0;
    scanf("%d.%d.%d", &a1, &a2, &a3);
    scanf("%d.%d.%d", &b1, &b2, &b3);
    if(a3 + b3 >= 29)
    {
        f = 1;
        c3 = (a3 + b3) - 29;
    }
    else{
        c3 = (a3 + b3);
        f = 0 ; 
    }

    if(a2 + b2 + f >= 17)
    {
        c2 = (a2 + b2 + f) - 17;
        f = 1;
    }
    else{
        c2 = a2 + b2 + f;
        f = 0;
    }
    c1 = a1 + b1 + f;
    printf("%d.%d.%d\n", c1, c2, c3 );
    return 0;
}

