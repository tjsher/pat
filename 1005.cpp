#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res += s[i] - '0';
    }

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                      "eight", "nine"
                     };

    s = to_string(res);
    cout << arr[s[0] - '0'];
    for(int i = 1; i <= s.length(); i++)
    {
        cout << arr[s[i] - '0']<<endl;
    }
    return 0;

}