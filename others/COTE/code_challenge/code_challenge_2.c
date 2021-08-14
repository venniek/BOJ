#include <string>
#include <vector>

using namespace std;

int is_match(char le, char s)
{
	if (le == '(' && s == ')')
		return (1);
	if (le == '{' && s == '}')
		return (1);
	if (le == '[' && s == ']')
		return (1);
	return (0);
}

int is_right(string s, int len)
{
 	char le[1001];
	int l = -1;
    
	for (int i = 0; i < len; i++)
	{
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
	    	le[++l] = s[i];
		else
		{
            if (l == -1)
                return (-1);
		    if (is_match(le[l], s[i]) == 1)
				l--;
			else
				return (-1);
		}
	}
    if (l != -1)
        return (-1);
	return (1);
}

void pull_str(string *s, int len)
{
	char c = (*s)[0];
	
	for (int i = 0; i < len - 1; i++)
		(*s)[i] = (*s)[i + 1];
	(*s)[len - 1] = c;
}

int solution(string s) {
    int answer = 0;
    int i = 0;
    int len;
    
    len = size(s);
    while (i < len)
    {
        pull_str(&s, len);
        if (is_right(s, len) == 1)
            answer++;
        i++;
    }
    return answer;
}
