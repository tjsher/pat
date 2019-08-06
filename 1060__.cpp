#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, ci, di;
    i  = 0;
    string a, b, c, d;
    c = d = "0.";
    scanf("%d", &n);
    cin >> a >> b;
    ci = a.size();
    di = b.size();
    int len = a.size() > b.size() ? b.size() : a.size();
    for(i = 0; i < a.size(); i++)
        if(a[i] == '.')
        {
            ci = i;
            break;
        }

    for(i = 0; i < b.size(); i++)
        if(b[i] == '.')
        {
            di = i;
            break;
        }
    i = 0;
    while(i < a.size() && i < n)
    {
        if(a[i] == '.')
        {
            i++;
            continue;
        }
        c += a[i];
        i++;
    }
    if(i < n)
    {
        c += '0';
        i++;
    }
    i = 0;
    while(i < b.size() && i < n)
    {
        if(b[i] == '.')
        {
            i++;
            continue;
        }
        d += b[i];
        i++;
    }
    if(i < n)
    {
        d += '0';
        i++;
    }
    if(c == d && ci==di)    
        cout << "YES " << c << "*10^" << ci;
    else
        cout << "NO " << c << "*10^" << ci<< " " << d << "*10^" << di;
    return 0;
}