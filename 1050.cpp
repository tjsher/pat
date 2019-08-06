#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int asc[128];
    fill(asc, asc + 128, 0);
    string s1, s2,res = "";
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.size(); i++)
        asc[s2[i]] = 1;

    for(int i = 0; i < s1.size(); i++)
    {
        if(asc[s1[i]] == 1)
            continue;
        res += s1[i];
    }
    cout << res;
    return 0;
}