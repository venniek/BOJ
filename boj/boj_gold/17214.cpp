#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string ans;
    int tmp = 0;
    int i = 0;

    cin >> str;
    if (str[i] == '-')
    {
        ans += '-';
        i++;
    }
    else if (str[i] == '0')
    {
        ans += 'W';
        i++;
    }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            tmp = tmp * 10 + str[i++] - '0';
        else if (str[i] == 'x')
        {
            int cnt = 1;
            while (str[i++] == 'x')
                cnt++;
            i--;
            if (tmp /= cnt != 1)
                ans += to_string(tmp);
            while (cnt--)
                ans += 'x';
            tmp = 0;
        }
        else
            ans += str[i++];
        if (str[i] == '\0')
        {
            if (tmp != 0)
            {
                if (tmp != 1)
                    ans += to_string(tmp);
                ans += 'x';
            }
            ans += "+W";
            break;
        }
    }
    cout << ans;
    return 0;
}