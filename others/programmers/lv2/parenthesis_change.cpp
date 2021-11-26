#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p)
{
    string answer = "";
    int left = 0, right = 0;
    string u, v;
    if (p == "")
        return answer;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            left++;
        else
            right++;
        if (left == right)
        {
            for (int j = 0; j < i + 1; j++)
                u += p[j];
            for (int j = i + 1; j < p.length(); j++)
                v += p[j];
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
                answer = '(';
                answer += solution(v);
                answer += ')';
                for (int j = 1; j < u.length() - 1; j++)
                    answer += u[j] == '(' ? ')' : '(';
                return answer;
            }
            s.pop();
        }
    }
    return u + solution(v);
}
