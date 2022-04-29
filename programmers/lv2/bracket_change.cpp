#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p)
{
    string answer = "";
    int balance = 0;
    string u, v;
    if (p == "")
        return answer;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            balance++;
        else
            balance--;
        if (balance == 0)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1, p.length() - i - 1);
            break;
        }
    }
    stack<char> s;
    for (int i = 0; i < u.length(); i++)
    {
        if (u[i] == '(')
            s.push(u[i]);
        else
        {
            if (s.empty())
            {
                answer = '(' + solution(v) + ')';
                for (int j = 1; j < u.length() - 1; j++)
                    answer += u[j] == '(' ? ')' : '(';
                return answer;
            }
            s.pop();
        }
    }
    return u + solution(v);
}
