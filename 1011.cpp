#include <iostream>

using namespace std;

int main()
{

    char three[4] = {"WTL"};
    double m, temp, res = 1.0;
    for(int i = 0; i < 3; i++)
    {
        int choose = 0;
        temp = 0.0;
        for(int j = 0; j < 3; j++)
        {
            scanf("%lf", &m);
            if(temp <= m)
            {
                temp = m;
                choose = j;
            }

        }
        res *= temp;
        printf("%c ", three[choose]);

    }

res = ( res * 0.65 - 1) *2;
printf("%.2lf", res);
return 0;
}