#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> num;
vector<char> op;

int main()
{
    string str;
    int tmp = 0;

    cin >> str;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            tmp = tmp * 10 + str[i] - '0';
        else
        {
            num.push_back(tmp);
            op.push_back(str[i]);
            tmp = 0;
        }
        if (str[i + 1] == '\0')
            num.push_back(tmp);
    }
    for (int i = 1; i < op.size(); i++)
    {
        if (op[i] == '+')
        {
            num[i + 1] += num[i];
            num[i] = 0;
            op[i] = op[i - 1];
        }
    }
    tmp = num[0];
    for (int i = 1; i < num.size(); i++)
        tmp += op[i - 1] == '+' ? num[i] : num[i] * -1;
    cout << tmp;
    return 0;
}