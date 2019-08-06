#include <iostream>
using namespace std;

string To13(int s)
{
    int n, t = 0, i = 1;
    char q;
    string res = "";
    n = s;
    if(n == 0)
        res += '0';
    while(n > 0)
    {
        t = n % 13;
        n = n / 13;
        if(t >= 10)
        {
            q = 'A' + t - 10;
            res =  q + res ;
        }
        else
        {
            q = ('0' + t);
            res =  q + res ;
        }
    }
    if( s < 13)
        res = '0' + res;
    return res;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    cout<<"#"<<To13(a)<<To13(b)<<To13(c);
    return 0;
}