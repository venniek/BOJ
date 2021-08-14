#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string s) {
    int answer = 0;
    char *eng[10];
    char str[6];
    char ans[51];
    
    eng[0] = "zero";
    eng[1] = "one";
    eng[2] = "two";
    eng[3] = "three";
    eng[4] = "four";
    eng[5] = "five";
    eng[6] = "six";
    eng[7] = "seven";
    eng[8] = "eight";
    eng[9] = "nine";
    
    int i = 0;
    int k = 0;
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            ans[k++] = s[i++];
        else
        {
            int j = 0;
            while (s[i] >= 'a' && s[i] <= 'z')
            {
                str[j++] = s[i++];
                str[j] = '\0';
                for (int t = 0; t < 10; t++)
                {
                    if (strcmp(eng[t], str) == 0)
                    {
                        ans[k++] = t + '0';
                        str[0] = '\0';
                        j = 0;
                        break;
                    }
                }
            }
            str[0] = '\0';
        }
    }
    ans[k] = '\0';
    for (int i = 0; i < k; i++)
        answer = answer * 10 + ans[i] - '0';
    return answer;
}
