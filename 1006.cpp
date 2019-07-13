#include <iostream>

using namespace std;

int main()
{
    int m;
    string id, inTime, outTime;
    scanf("%d", &m);
    string minId,maxId,maxTime = "00:00:00",minTime="99:99:99";
    for(int i = 0; i < m; i++)
    {
        cin >> id ;
        cin >> inTime;
        cin >> outTime;
        if(inTime <= minTime){
            minTime = inTime;
            minId = id;
        }
        if(outTime >= maxTime){
            maxTime = outTime;
            maxId = id;
        }
    }
    cout << minId <<" "<<maxId;
    return 0;
}