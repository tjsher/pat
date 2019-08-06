#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool isPrime(int n)
{
    if(n <= 2)
        return  true;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

map <string, int> _rank;
int main()
{
    int n;
    string s;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        _rank[s] = i;
    }
    if(n == 0)
        return 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(_rank[s] == 0)
        {
            cout << s << ": Are you kidding?" << endl;

            continue;
        }
        if( _rank[s] == 1)
        {
            cout << s << ": Mystery Award" << endl;
            continue;
        }
        if( _rank[s] == -1)
        {
            cout << s << ": Checked" << endl;
            continue;
        }
        if(isPrime(_rank[s]) == true )
        {
            _rank[s] = -1;
            cout << s << ": Minion" << endl;
        }
        else
        {
            _rank[s] = -1;
            cout << s << ": Chocolate" << endl;
        }
    }
    return 0;
}