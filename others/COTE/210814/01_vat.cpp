#include <string>
#include <vector>
using namespace std;

long long solution(long long orderAmount, long long taxFreeAmount, long long serviceFree)
{
	long long answer = 0;
	long long Amount = orderAmount - serviceFree - taxFreeAmount;

	if (Amount != 1)
	{
		if (Amount % 11 == 0)
			answer = Amount / 11;
		else
			answer = Amount / 11 + 1;
	}
	return answer;
}
