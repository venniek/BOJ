#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<int> student(n + 2, 1);

	for (int i : reserve)
		student[i]++;
	for (int i : lost)
		student[i]--;
	for (int i = 1; i <= n; i++)
	{
		if (student[i] == 0)
		{
			if (student[i - 1] == 2)
				student[i] = student[i - 1] = 1;
			else if (student[i + 1] == 2)
				student[i] = student[i + 1] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (student[i] != 0) answer++;
	return answer;
}
