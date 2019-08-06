#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
int n, k = 0, f;
    string s;
    double res = 0, a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        int c = 0, t = 0;
        f = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] < '0' || s[j] > '9' || c > 1)
            {
                if((s[j] != '.' && s[j] != '-') || c > 1)
                {
                    f = 1;
                    break;

                }

            }
            if(s[j] == '.')
            {
                c++;
                t = j;
            }
        }
        if(f == 0)
        {
            a = atof(s.c_str());
            if(a < -1000.0 || a > 1000.0 || s.size() - t > 3)
                f = 1;
        }
        if(f == 1)
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
            continue;
        }
        res += a;
        k++;
    }
    if(k == 1)
        printf("The average of %d number is %.2lf\n", k, res / k );
    else if (k == 0)
        printf("The average of %d numbers is ndefined\n", k);

    else
        printf("The average of %d numbers is %.2lf\n", k, res / k );




    return 0;
}