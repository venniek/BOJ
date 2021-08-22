#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> fruit, int k)
{
	vector<int> answer;
	priority_queue<int> num;
	int len = fruit.size();
	int tmp;

	for (int i = 0; i <= len - k; i++)
	{
		tmp = 0;
		for (int j = 0; j < k; j++)
			tmp = max(tmp, fruit[i + j]);
		num.push(tmp);
	}
	len = num.size();
	for (int i = 0; i < len; i++)
	{
		if (answer.empty() || answer.back() != num.top())
			answer.push_back(num.top());
		num.pop();
	}
	return answer;
}
