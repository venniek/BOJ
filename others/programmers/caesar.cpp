#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    char tmp;
    
    for (int i = 0; i < s.length(); i++)
    {
        tmp = s[i];
        if (tmp >= 'a' && tmp <= 'z')
        {
            tmp += n - 26;
            if (tmp < 'a')
                tmp += 26;
        }
        else if (tmp >= 'A' && tmp <= 'Z')
        {
            tmp += n;
            if (tmp > 'Z')
                tmp -= 26;
        }
        answer += tmp;
    }
    return answer;
}
