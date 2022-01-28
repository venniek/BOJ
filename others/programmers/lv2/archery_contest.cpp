#include <string>
#include <vector>
#include <iostream>
using namespace std;

int tmp[11];
int ans[11];
int maxscore;

int cmp_score(vector<int> info)
{
    int ryan = 0;
    int apeach = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (info[i] != 0 && info[i] >= tmp[i])
            apeach += 10 - i;
        else if (tmp[i] > info[i])
            ryan += 10 - i;
    }
    return (ryan - apeach);
}

void cmp_max()
{
	for (int i = 10; i >= 0; i--)
	{
		if (tmp[i] < ans[i])
			break ;
		if (tmp[i] > ans[i])
		{
			for (int j = 0; j < 11; j++)
				ans[j] = tmp[j];
			break;
		}
	}
}

void make_score(int n, vector<int> info, int now)
{
    if (n == 0 || now == 11)
    {
        if (n != 0)
            tmp[now - 1] += n;
		else
		{
			for (int i = now; i < 11; i++)
				tmp[i] = 0;
		}
		int temp = cmp_score(info);
		if (temp != 0 && temp == maxscore)
			cmp_max();
		else if (temp > maxscore)
        {
            maxscore = temp;
            for (int i = 0; i < 11; i++)
                ans[i] = tmp[i];
        }
        return ;
    }
    if (info[now] + 1 <= n)
    {
        tmp[now] = info[now] + 1;
        make_score(n - tmp[now], info, now + 1);
    }
    tmp[now] = 0;
    make_score(n, info, now + 1);
	tmp[now] = 0;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    make_score(n, info, 0);
    if (maxscore == 0)
        answer.push_back(-1);
    else
    {
        for (int i = 0; i < 11; i++)
            answer.push_back(ans[i]);
    }
    return answer;
}
