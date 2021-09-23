#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
	while (n > 0)
	{
		answer += n % 3 + '0';
		n /= 3;
	}
    reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		int k = i;
		while (k > 0 && answer[k] == '0')
		{
			answer[k - 1] = (answer[k - 1] - '0') / 2 + '0';
			answer[k] = '4';
			k--;
		}
	}
	if (answer[0] == '0')
		answer.erase(0, 1);
    return answer;
}
