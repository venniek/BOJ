#include <string>
#include <vector>

using namespace std;

long long stair[71];

long long solution(int numOfStairs)
{
	long long answer = 0;

	stair[1] = 1;
	stair[2] = 2;
	stair[3] = 3;
	for (int i = 4; i <= numOfStairs; i++)
		stair[i] = stair[i - 1] + stair[i - 2] + stair[i - 3];
	answer = stair[numOfStairs];
	return answer;
}
