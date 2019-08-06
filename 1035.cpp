#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector <string> name;
vector <string> pass;
int main()
{
    int n, count;
    scanf("%d", &n);
    bool flag = false;
    string a, b;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a >> b;
        flag = false;
        for(int j = 0; j < b.size() ; j++)
        {
            if(b[j] == '1' || b[j] == 'l' || b[j] == '0'|| b[j] == 'O')
            {
                flag = true;
                if(b[j] == '1')
                    b[j] = '@';
                if(b[j] == 'l')
                    b[j] = 'L';
                if(b[j] == '0')
                    b[j] = '%';
                if(b[j] == 'O')
                    b[j] = 'o';
            }
        }
        if(flag == true)
        {
            count ++;
            name.push_back(a);
            pass.push_back(b);
        }
    }
    if(n == 1 && count == 0)
        printf("There is 1 account and no account is modified");
    if(n > 1 && count == 0)
        printf("There is %d accounts and no account is modified", n);
    if(count != 0)
    {
        printf("%d\n", count );
        for(int i = 0; i < pass.size(); i++)
        {
            string q = name[i] +" "+ pass[i];
            cout << q << endl;
        }
    }



    return 0;
}