/*
没有给出会有多少楼层任务，
将读取写入循环
*/
#include <iostream>
using namespace std;
int main()
{
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a)
    {
        if(a > now)
            sum = sum + 6 * (a - now);
        else
            sum = sum + 4 * (now - a);
        now = a;
        sum += 5;
    }
    cout << sum;
    return 0;
}