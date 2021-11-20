#include <string>
#include <vector>

using namespace std;

vector<vector<int> > g_upg;
int answer, n, g_gold;

void use_till_end(int i, int time, int money)
{
	money += time / g_upg[i][1] * g_gold;
	answer = max(answer, money);
}

void upgrade_gok(int i, int time, int money)
{
	if (i == n - 1)
	{
		while (time > 0)
		{
			time -= g_upg[i][1];
			money += g_gold;
		}
		answer = max(answer, money);
		return ;
	}
	while (time >= g_upg[i][1] && money < g_upg[i + 1][0])
	{
		time -= g_upg[i][1];
		money += g_gold;
	}
	if (time == 0)
		answer = max(answer, money);
	else
	{
		money -= g_upg[i + 1][0];
		use_till_end(i + 1, time, money);
		upgrade_gok(i + 1, time, money);
	}
}

int solution(int time, int gold, vector<vector<int> > upgrade) {
    n = upgrade.size();
	g_gold = gold;
	for (int i = 0; i < n; i++)
		g_upg.push_back(upgrade[i]);
	use_till_end(0, time, 0);
	upgrade_gok(0, time, 0);

    return answer;
}