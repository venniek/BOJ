#include <string>
#include <vector>

using namespace std;

string is_right(string str)
{
	string ret = "";
	int sum = 0; int notright = 0;

	for (int i = 0; i < str.size(); i++)
	{
		sum += str[i] == '(' ? 1 : -1;
		if (sum < 0)
		{
			notright = 1;
			break;
		}
	}
	if (notright == 1)
	{
		
	}
}

string solution(string p) {
    string answer = "";
    string u = "";
    string v = "";
    if (p.size() == 0)
        return answer;
	int sum = 0;
    for (int i = 0; i < p.size(); i++)
    {
        sum += p[i] == '(' ? 1 : -1;
        u += p[i];
        if (sum == 0)
        {
            for (int j = i + 1; j < p.size(); j++)
                v += p[j];
            break;
        }
    }
    answer += is_right(u);
    answer += is_right(v);
    return answer;
}