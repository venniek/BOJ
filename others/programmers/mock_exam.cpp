#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ret;
    vector<int> su1;
    vector<int> su2;
    vector<int> su3;
    int len = answers.size();
    int tmp;

    for (int i = 0; i < len; i++)
    {
        su1.push_back(i % 5 + 1);
        tmp = i % 8;
        if (tmp % 2 == 0)
            su2.push_back(2);
        else if (tmp == 1 || tmp == 3)
            su2.push_back(tmp);
        else if (tmp == 5)
            su2.push_back(4);
        else if (tmp == 7)
            su2.push_back(5);
        tmp = i % 10;
        if (tmp == 0 || tmp == 1)
            su3.push_back(3);
        else if (tmp == 2 || tmp == 3)
            su3.push_back(1);
        else if (tmp == 4 || tmp == 5)
            su3.push_back(2);
        else if (tmp == 6 || tmp == 7)
            su3.push_back(4);
        else if (tmp == 8 || tmp == 9)
            su3.push_back(5);
    }
    for (int i = 0; i < len; i++)
    {
        su1[i] = su1[i] == answers[i] ? 1 : 0;
        su2[i] = su2[i] == answers[i] ? 1 : 0;
        su3[i] = su3[i] == answers[i] ? 1 : 0;
    }
    for (int i = 1; i < len; i++)
    {
        su1[i] += su1[i - 1];
        su2[i] += su2[i - 1];
        su3[i] += su3[i - 1];
    }
    tmp = max(su1[len - 1], su2[len - 1]);
    tmp = max(tmp, su3[len - 1]);
    if (su1[len - 1] == tmp)
        ret.push_back(1);
    if (su2[len - 1] == tmp)
        ret.push_back(2);
    if (su3[len - 1] == tmp)
        ret.push_back(3);
    return ret;
}
