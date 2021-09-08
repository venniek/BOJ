#include <iostream>
#include <string>

using namespace std;

int nummatch[26];
int is_done[8];
int exist[26];
int ans;
string g_1, g_2, g_3;

int is_right()
{
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < g_1.size(); i++)
		a = a * 8 + nummatch[g_1[i] - 'a'];
	for (int i = 0; i < g_2.size(); i++)
		b = b * 8 + nummatch[g_2[i] - 'a'];
	for (int i = 0; i < g_3.size(); i++)
		c = c * 8 + nummatch[g_3[i] - 'a'];
	if (a + b == c)
		return 1;
	return 0;
}

void fill_nummatch(int cnt, int alpha)
{
	if (cnt == 0 || alpha == 26)
	{
		if (is_right() == 1)
			ans++;
		return ;
	}
	if (exist[alpha] == 0)
		fill_nummatch(cnt, alpha + 1);
	for (int i = 0; i < 8; i++)
	{
		if (is_done[i] == 1)
			continue;
		nummatch[alpha] = i;
		is_done[i] = 1;
		fill_nummatch(cnt - 1, alpha + 1);
		is_done[i] = 0;
	}
}


void solution(string num1, string num2, string num3)
{
	g_1 = num1;
	g_2 = num2;
	g_3 = num3;

	for (int i = 0; i < num1.size(); i++)
		exist[num1[i] - 'a'] = 1;
	for (int i = 0; i < num2.size(); i++)
		exist[num2[i] - 'a'] = 1;
	for (int i = 0; i < num3.size(); i++)
		exist[num3[i] - 'a'] = 1;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		cnt += exist[i] == 1 ? 1 : 0;
	fill_nummatch(cnt, 0);
	if (cnt == 8)
		return ;
	for (int i = 8 - cnt; i > 0; i--)
		ans *= i;
}

int main(int ac, char **av)
{
	int answer;
	string num1 = av[1];
	string num2 = av[2];
	string num3 = av[3];
	solution(num1, num2, num3);
	cout << ans;
	return 0;
}