#include <iostream>
#include <algorithm>
using namespace std;


bool isPal(string n)
{
    int j = 0;
    bool flag = true;
    for(int i = n.size() - 1; i >= 0; i--, j++)
    {
        if(j > i) break;
        if(n[j] != n[i])
            flag = false;
    }
    return flag;

}
int main()
{

    string n, r;
    int k, t = 0, flag = 0, temp1, temp2;
    cin >> n;
    scanf("%d", &k);

    for(int i = 0; i < k; i++, t++)
    {
        if(isPal(n))
            break;
        r = n;
        flag = 0;
        reverse(n.begin(), n.end());
        for(int j = n.size() - 1; j >= 0; j--)
        {
            temp1 = n[j] - '0';
            temp2 = r[j] - '0';
            if(temp1 + temp2 + flag >= 10)
            {
                n[j] = temp1 + temp2 + flag - 10 + '0';
                flag = 1;
            }
            else
            {
                n[j] = temp1 + temp2 + flag + '0';
                flag = 0;
            }
        }
        if(flag == 1)
            n = '1' + n;


    }
    cout << n << endl << t;
    return 0;
}